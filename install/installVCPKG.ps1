# https://github.com/Microsoft/vcpkg/tree/master/docs/examples
Write-Host "Installing.. 'vcpkg' package manager, more:"
Write-Host "https://github.com/Microsoft/vcpkg"
Write-Host "Current Directory: $((Get-Location).path)"
Write-Host "Nexss $($env:NEXSS_HOME_PATH)"
$cwd = (Get-Location).path
$installPath = "$($Env:NEXSS_APPS_PATH)\vcpkg"
$exeFile = "$($installPath)\vcpkg.exe"

Write-Host "InstallPath: $($installPath)"

if (!(Test-Path $exeFile -PathType Leaf)) {
    if (Test-Path $installPath ) {
        Write-Host "$installPath does exist. Update vcpkg.."
        cd vcpkg
        git pull
        cd ..
    }
    else {
        git clone https://github.com/Microsoft/vcpkg $installPath
    }

    cd $installPath
    Write-Host "Execute installation script: cmd /c bootstrap-vcpkg.bat"
    cmd /c bootstrap-vcpkg.bat -disableMetrics
}

Write-Host "Add vcpkg to the system path.."

# Change User to Machine  
[System.Environment]::SetEnvironmentVariable("Path", "$env:Path;$installPath", "User") # for the user
$env:Path = [System.Environment]::GetEnvironmentVariable("Path", "Machine") + ";" + [System.Environment]::GetEnvironmentVariable("Path", "User") 

vcpkg integrate install
Write-Host "Integrate vcpkg with Powershell.."
vcpkg integrate powershell
Write-Host "vcpkg has been installed."