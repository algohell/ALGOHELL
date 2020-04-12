const axios = require("axios");

const githubApi = axios.create({
  baseURL: "https://api.github.com",
});

const slackApi = axios.create({
  baseURL: "https://slack.com/api",
});

module.exports = {
  githubApi,
  slackApi,
};
