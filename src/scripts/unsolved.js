require("dotenv").config();
const moment = require("moment-timezone");

const { githubApi } = require("../fetcher");
const { GITHUB_DATA, LABELS, ISSUE_STATE } = require("../constants");

const { owner, repo } = GITHUB_DATA;

const LINK_REGEX = /https?:\/\/(www\.)?[-a-zA-Z0-9@:%._\+~#=]{1,256}\.[a-zA-Z0-9()]{1,6}\b([-a-zA-Z0-9()@:%_\+.~#?&//=]*)/gi;

(async () => {
  try {
    const { data } = await githubApi.get(`/repos/${owner}/${repo}/issues`, {
      params: {
        state: ISSUE_STATE.All,
        labels: LABELS.unsolved,
      },
    });
    const issues = data.filter(({ pull_request }) => !pull_request);

    const issuesComments = await Promise.all(
      issues.map(({ number }) => {
        return githubApi(
          `/repos/${owner}/${repo}/issues/${number}/comments`
        ).then(({ data }) => ({ number, comments: data }));
      })
    );

    const list = [];

    issuesComments.forEach(({ number, comments }) => {
      const unsolvedComments = comments
        .filter((comment) => comment.body.startsWith("unsolved"))
        .flatMap((comment) => comment.body.match(LINK_REGEX));

      unsolvedComments.length > 0 &&
        list.push({
          number,
          comments: unsolvedComments,
        });
    });

    const text = `

### 못푼 문제들
${list
  .map(
    ({ number, comments }) =>
      `#${number}
${comments.map((comment) => `- ${comment}`).join("\n")}
`
  )
  .join("\n\n")}
`;

    const { data: unsolvedColectionIssue } = await githubApi.get(
      `/repos/${owner}/${repo}/issues`,
      {
        params: {
          state: ISSUE_STATE.All,
          labels: LABELS.unsolvedCollection,
        },
      }
    );
    const hasUnsolvedCollection = unsolvedColectionIssue.length > 0;
    const body = {
      title: `못푼 문제들 - ${moment().tz("Asia/Seoul").format("MM/DD")}`,
      body: text,
    };

    if (!hasUnsolvedCollection) {
      await githubApi.post(`/repos/${owner}/${repo}/issues`, {
        ...body,
        labels: [LABELS.unsolvedCollection],
      });
    } else {
      const { number } = unsolvedColectionIssue[0];
      await githubApi.patch(`/repos/${owner}/${repo}/issues/${number}`, body);
    }
  } catch (err) {
    console.error(err);
  }
})();
