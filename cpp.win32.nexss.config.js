let languageConfig = Object.assign(
  {},
  require(`../config.${process.platform}`)
);
languageConfig.title = "C++";
languageConfig.description =
  "C++ is a general-purpose programming language created by Bjarne Stroustrup.";
languageConfig.url = "https://isocpp.org/";
languageConfig.founders = ["Bjarne Stroustrup"];
languageConfig.developers = [""];
languageConfig.years = ["1983"];
languageConfig.extensions = [".cpp", ".cc"];
const installVCPKG = `${__dirname}/install/installVCPKG.ps1`;
let vcpkgIncludePath;
let VCpkgPath;
if (process.platform === "win32") {
  try {
    vcpkgIncludePath = require("child_process")
      .execSync(`cmd /c where vcpkg`)
      .toString()
      .trim();
  } catch (error) {
    console.log("vcpkg seems to be not installed, installing..");

    require("child_process").execSync(
      `Powershell -ExecutionPolicy ByPass -File ${installVCPKG}`,
      {
        stdio: "inherit",
      }
    );
  }
}

if (process.platform === "win32") {
  if (!vcpkgIncludePath) {
    try {
      vcpkgIncludePath = require("child_process")
        .execSync(`cmd /c where vcpkg`, {
          stdio: "inherit",
        })
        .toString()
        .trim();
    } catch (error) {
      displayError();
      process.exit(1);
    }
    if (!vcpkgIncludePath) {
      console.error(
        "There was an error during setup of vcpkg which is package manager for C++."
      );
      const vcpkgExe = `${process.cwd()}/vcpkg/vcpkg.exe`;
      if (require("fs").existsSync(vcpkgExe)) {
        displayError();
      }
      process.exit(1);
    }
  }
  let triplet = "x64-windows";
  if (process.arch !== "x64") {
    triplet = "x86-windows";
  }

  triplet = "x86-windows";

  VCpkgPath = `${require("path").dirname(
    vcpkgIncludePath
  )}/installed/${triplet}/include`;
  languageConfig.builders = {
    gcc: {
      install: "scoop install gcc",
      command: "g++",
      build: () => {
        let triplet = "x64-windows";
        if (process.arch !== "x64") {
          triplet = "x86-windows";
        }
        process.env.VCPKG_DEFAULT_TRIPLET = triplet;
        return "g++";
      },
      // build: function() {
      //   const path = require("path");
      //   //take command from current folder
      //   return `${path.join(__dirname, "customCompiler.win32.cpp.cmd")}`;
      // },
      args: `-std=c++17 -isystem ${VCpkgPath} -o <destinationFile> <file> && <destinationFile>`,
      // C++ needs to be build to exe, so no compile option
      help: ``,
    },
    "g++": {
      install: "scoop install llvm",
      command: "g++",
      args: "-o <file>.exe && <file>.exe && rm <file>.exe",
      help: ``,
    },
  };
}
languageConfig.compilers = {};
languageConfig.errors = require("./nexss.cpp.errors");
if (process.platform === "win32") {
  languageConfig.languagePackageManagers = {
    vcpkg: {
      installation: `PowerShell.exe -File ${__dirname}/install/installVCPKG.bat`,
      messageAfterInstallation: "", //this message will be displayed after this package manager installation, maybe some action needed etc.
      installed: "vcpkg list",
      search: "vcpkg search",
      install: "vcpkg install",
      update: "bootstrap-vcpkg.bat && vcpkg update",
      uninstall: "vcpkg remove",
      help: "vcpkg --help",
      version: "vcpkg version",
      init: () => {
        try {
          require("child_process").execSync("vcpkg integrate project");
          console.log("initialized vcpkg project.");
        } catch (error) {
          // console.error(error);
        }
      },
      else: "vcpkg",
    },
  };
}

function displayError() {
  console.error(
    "\x1b[33mvcpkg not found. Have you restarted terminal/powershell?"
  );
  console.error(
    `Otherwise please add vckg path: ${process.env.NEXSS_APPS_PATH}/vcpkg to your system PATH variable.\x1b[0m`
  );
}

module.exports = languageConfig;
