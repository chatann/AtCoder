const https = require("https");

const url = "https://challenge-server.code-check.io/api/kidnapper";
const token = process.argv[2];

// /startへのアクセス
const start = () => {
  return new Promise((resolve, reject) => {
    const req = https.get(`${url}/start?token=${token}`, (res) => {
      let data = "";

      res.on("data", (chunk) => {
        data += chunk;
      });

      res.on("end", () => {
        const json = JSON.parse(data);
        resolve(json.goto);
      });
    });

    req.on("error", (error) => {
      reject(error);
    });
  });
};

// /deliverへのアクセス
const deliver = (to) => {
  return new Promise((resolve, reject) => {
    const req = https.get(`${url}/deliver?token=${token}&to=${to}`, (res) => {
      let data = "";

      res.on("data", (chunk) => {
        data += chunk;
      });

      res.on("end", () => {
        const json = JSON.parse(data);
        if (json.put_the_bag) {
          resolve(null);
        } else {
          resolve(json.goto);
        }
      });
    });

    req.on("error", (error) => {
      reject(error);
    });
  });
};

const main = async () => {
  try {
    let from = await start();
    let to = await deliver(from);
    while (to) {
      from = to;
      to = await deliver(from);
    }
    console.log(from);
  } catch (error) {
    console.error(error);
  }
};

main();
