del *.log
Write-Output "Remove previous hls iplib..."
Remove-Item -recurse -Force ..\..\iplib\phasegen\
Remove-Item -recurse -Force ..\..\iplib\devnullphase\
Remove-Item -recurse -Force ..\..\iplib\devnulldata\
Remove-Item -recurse -Force ..\..\iplib\devnullmaster\
Remove-Item -recurse -Force ..\..\iplib\dynamics\
Remove-Item -recurse -Force ..\..\iplib\nco\
Remove-Item -recurse -Force ..\..\iplib\vca\
Remove-Item -recurse -Force ..\..\iplib\vcamaster\
Write-Output "Remove previous hls project folders..."
Remove-Item -recurse -Force .\phasegen\
Remove-Item -recurse -Force .\devnullphase\
Remove-Item -recurse -Force .\devnulldata\
Remove-Item -recurse -Force .\devnullmaster\
Remove-Item -recurse -Force .\dynamics\
Remove-Item -recurse -Force .\nco\
Remove-Item -recurse -Force .\vca\
Remove-Item -recurse -Force .\vcamaster\
Write-Output "Remove Vivado projects..."
Remove-Item -recurse -Force .\testnco\
Remove-Item -recurse -Force .\testphasegen\
