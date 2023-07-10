const https = require("https");
const url = "https://challenge-server.code-check.io/api/hash";
const q = process.argv[2];

const hash = (q) => {
  q = encodeURIComponent(q);
  const req = https.get(`${url}?q=${q}`, (res) => {
    let data = "";

    res.on("data", (chunk) => {
      data += chunk;
    });

    res.on("end", () => {
      const json = JSON.parse(data);
      console.log(json.hash);
    });
  });
};

hash(q);
