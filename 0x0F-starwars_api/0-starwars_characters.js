#!/usr/bin/node

const request = require('request');
const process = require('process');

function getCharacter (characters, i) {
  if (characters.length <= i) {
    return;
  }

  request(characters[i], function (_error, response) {
    console.log(JSON.parse(response.body).name);

    getCharacter(characters, i + 1);
  });
}

function main () {
  if (process.argv.length < 3) {
    return;
  }

  const film = process.argv[2];
  request(`https://swapi-api.hbtn.io/api/films/${film}`, function (_error, response) {
    const characters = JSON.parse(response.body).characters;

    getCharacter(characters, 0);
  });
}

main();
