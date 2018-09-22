$vivadopath = Read-Host 'What is vivado path?'
$pathok = Test-Path $vivadopath
If ($pathok -eq $True) 
{    
    $fullpath = Join-Path $vivadopath '\bin\vivado_hls.bat ..//hls.build.zybe.tcl'    
    
    del *.log
    Write-Output "Starting hls build..."
    Write-Output "Remove previous hls iplib..."
    Remove-Item -recurse -Force ..\..\iplib\zyiplib\phasegen\
    Remove-Item -recurse -Force ..\..\iplib\zyiplib\devnullphase\
    Remove-Item -recurse -Force ..\..\iplib\zyiplib\devnulldata\
    Remove-Item -recurse -Force ..\..\iplib\zyiplib\devnullmaster\
    Remove-Item -recurse -Force ..\..\iplib\zyiplib\dynamics\
    Remove-Item -recurse -Force ..\..\iplib\zyiplib\nco\
    Remove-Item -recurse -Force ..\..\iplib\zyiplib\ca\
    Remove-Item -recurse -Force ..\..\iplib\zyiplib\vcamaster\
    Write-Output "Remove previous hls project folders..."
    Remove-Item -recurse -Force .\.build\phasegen\
    Remove-Item -recurse -Force .\.build\devnullphase\
    Remove-Item -recurse -Force .\.build\devnulldata\
    Remove-Item -recurse -Force .\.build\devnullmaster\
    Remove-Item -recurse -Force .\.build\dynamics\
    Remove-Item -recurse -Force .\.build\nco\
    Remove-Item -recurse -Force .\.build\vca\
    Remove-Item -recurse -Force .\.build\vcamaster\
    Write-Output "hls build..."
    mkdir .\.build
    mkdir ..\..\iplib\zyiplib\
    cd .\.build
    Write-Output $fullpath
    Invoke-Expression -Command $fullpath
    Write-Output "move new hls build in iplib..."
    Move-Item -path .\phasegen\zybe\impl\ip\ -destination ..\..\..\iplib\zyiplib\
    Rename-Item ..\..\..\iplib\zyiplib\ip phasegen
    Move-Item -path .\devnullphase\zybe\impl\ip\ -destination ..\..\..\iplib\zyiplib\
    Rename-Item ..\..\..\iplib\zyiplib\ip devnullphase
    Move-Item -path .\devnulldata\zybe\impl\ip\ -destination ..\..\..\iplib\zyiplib\
    Rename-Item ..\..\..\iplib\zyiplib\ip devnulldata
    Move-Item -path .\devnullmaster\zybe\impl\ip\ -destination ..\..\..\iplib\zyiplib\
    Rename-Item ..\..\..\iplib\zyiplib\ip devnullmaster
    Move-Item -path .\dynamics\zybe\impl\ip\ -destination ..\..\..\iplib\zyiplib\
    Rename-Item ..\..\..\iplib\zyiplib\ip dynamics
    Move-Item -path .\nco\zybe\impl\ip\ -destination ..\..\..\iplib\zyiplib\
    Rename-Item ..\..\..\iplib\zyiplib\ip nco
    Move-Item -path .\vca\zybe\impl\ip\ -destination ..\..\..\iplib\zyiplib\
    Rename-Item ..\..\..\iplib\zyiplib\ip vca
    Move-Item -path .\vcamaster\zybe\impl\ip -destination ..\..\..\iplib\zyiplib\
    Rename-Item ..\..\..\iplib\zyiplib\ip vcamaster
    Write-Output "...build completed"
    cd ..\
}
Else 
{
    Write-Host "No valid folder exiting..."
}
