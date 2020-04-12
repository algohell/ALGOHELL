const axios = require("axios");

const githubApi = axios.create({
  baseURL: "https://api.github.com",
  headers: {
    Authorization: `Bearer ${process.env.GITHUB_TOKEN}`,
  },
});

const slackApi = axios.create({
  baseURL: "https://slack.com/api",
  headers: {
    Authorization: `Bearer ${process.env.SLACK_AUTH_TOKEN}`,
  },
});

module.exports = {
  githubApi,
  slackApi,
};
