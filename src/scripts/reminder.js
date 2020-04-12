const { slackApi, githubApi } = require("../fetcher");
const { GITHUB_DATA } = require("../constants");

require("dotenv").config();

const { owner, repo } = GITHUB_DATA;

(async () => {
  try {
    const { data } = await githubApi.get(`/repos/${owner}/${repo}/issues`);
    const latestIssue = data.find(({ pull_request }) => !pull_request);

    const { title, url, body } = latestIssue;

    const text = `
  
  *[:rocket: 이번 주 알고리즘]*
  <${url}|${title}>
  *[내용]*
  ${body}
    `;

    await slackApi.post(
      "/chat.postMessage",
      {
        token: process.env.SLACK_AUTH_TOKEN,
        channel: "#algorithm",
        text,
      },
      {
        headers: {
          Authorization: `Bearer ${process.env.SLACK_AUTH_TOKEN}`,
        },
      }
    );
  } catch (err) {
    console.log(err);
  }
})();
