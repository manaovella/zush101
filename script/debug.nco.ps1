$vivadopath = Read-Host 'What is vivado path?'
$pathok = Test-Path $vivadopath
If ($pathok -eq $True) 
{        
    $fullpath = Join-Path $vivadopath 'bin\vivado.bat -mode tcl -source ../../debug.nco.tcl'    
    cd .\.build\testnco
    Invoke-Expression -Command $fullpath
}
Else 
{
    Write-Host "No valid folder exiting..."    
}