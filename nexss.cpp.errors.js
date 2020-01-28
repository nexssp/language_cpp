module.exports = {
  "fatal error: '(.*?)' file not found.": "nexss install cpp <package>",
  "Cannot find module '(.*?)'": "nexss install cpp <package>",
  "Cannot open include file: 'dns_sd.h'": `Do you have bonjour SDK installed? 
https://developer.apple.com/download/more/
(Remember to restart your computer after installation.)`,
  "warning: unused variable '(.*?)'":
    "Variable '<found1>' is declared but never used. Please delete variable declaration or use it somewere in your code.",
  "'rapidjson/document.h' file not found": "xxxx",
  "fatal error: 'inttypes.h' file not found":
    "You may have installed another compiler (eg visualc 16). Uninstall eg scoop uninstall visualc"
};

//  "Cannot open include file: 'dns_sd.h'": {
//       win32:
//         "Do you have bonjour SDK installed (Remember to restart your computer after installation.)? https://developer.apple.com/download/more/",
//       darwin: "native? or edit error in " + __dirname,
//       linux: "apt-get install -y libavahi-compat-libdnssd-dev"
//     }
