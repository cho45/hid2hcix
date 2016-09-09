$SystemProperty = $(Get-ItemProperty 'HKLM:\SOFTWARE\Microsoft\Windows\CurrentVersion\Explorer\User Shell Folders')
$dest = $SystemProperty.'Common Startup' + "\hid2hcix.exe"

# $UserProperty = $(Get-ItemProperty 'HKCU:\SOFTWARE\Microsoft\Windows\CurrentVersion\Explorer\User Shell Folders')
# $dest = $UserProperty.Startup
echo $dest
Invoke-WebRequest -Uri "https://github.com/cho45/hid2hcix/releases/download/v1.0.0/hid2hcix.exe" -OutFile $dest
