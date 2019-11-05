// additional info for templates like copy extra libraries.
// in this case library needs JSONParser.ahk so lets specify it.
const config = {
  files: [],
  commands: {
    all: ["vcpkg install rapidjson"]
    // linux: ["nexss c mycommand"] //here also can be command from _nexss file
  },
  repos: ["https://github.com/Tencent/rapidjson.git"]
};

module.exports = config;
