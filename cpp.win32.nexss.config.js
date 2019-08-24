let languageConfig = Object.assign({}, require("../config.win32"));
languageConfig.title = "C++";
languageConfig.description =
  "C++ is a general-purpose programming language created by Bjarne Stroustrup.";
languageConfig.url = "https://isocpp.org/";
languageConfig.extensions = [".cpp", ".cc"];
languageConfig.compiler = "clang";
languageConfig.builders = {
  llvm: {
    install: "scoop install llvm",
    //build: "pkg --output <destinationFile> --out-path <destinationPath> <file>",
    command: "clang++",
    build: function() {
      const path = require("path");
      //take command from current folder
      return `${path.join(__dirname, "customCompiler.win32.cpp.cmd")}`;
    },
    args: "<file> <destinationFile>",
    // C++ needs to be build to exe, so no compile option
    help: ``
  },
  "g++": {
    install: "scoop install llvm",
    // Cpp does not have possibility to compile and run on the fly. We need to save it as a exe file first.
    command: "g++",
    args: "-o <file>.exe && <file>.exe && rm <file>.exe",
    help: ``
  }
};
languageConfig.compilers = {};
languageConfig.errors = require("./nexss.cpp.errors");
languageConfig.languagePackageManagers = {
  vcpkg: {
    installation: "PowerShell.exe -File installVCPKG.bat",
    messageAfterInstallation: "", //this message will be displayed after this package manager installation, maybe some action needed etc.
    installed: "vcpkg list",
    search: "vcpkg search",
    install: "vcpkg install",
    uninstall: "vcpkg remove",
    help: "vcpkg --help",
    version: "vcpkg version",
    init: () => {
      require("child_process").execSync("vcpkg integrate project");
      console.log("initialized vcpkg project.");
    },
    // if command not found in specification
    // run directly on package manager
    else: "vcpkg <default> <args>"
  }
};

module.exports = languageConfig;
// console.log(languageConfig.get(`errors`));
// console.log(languageConfig.get("author"));
// console.log(Object.keys(languageConfig.get("osPackageManagers")));
// console.log(Object.keys(languageConfig.get("languagePackageManagers")));
