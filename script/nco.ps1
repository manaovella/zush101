$vivadopath = Read-Host 'What is vivado path?'
$pathok = Test-Path $vivadopath
If ($pathok -eq $True) 
{    
    $fullpath = Join-Path $vivadopath '\bin\vivado.bat -mode tcl -source ../../nco.tcl'
    del *.log
    Remove-Item -recurse -Force .\.build\testnco\
    mkdir .\.build
    mkdir .\.build\testnco
    cd .\.build\testnco
    Write-Host $fullpath
    Invoke-Expression -Command $fullpath 
    cd ..\..\
}
Else 
{
    Write-Host "No valid folder exiting..."    
}
