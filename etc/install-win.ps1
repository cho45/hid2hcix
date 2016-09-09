
Unregister-ScheduledJob -Name HID2HCI

Invoke-WebRequest -Uri "https://github.com/cho45/hid2hcix/releases/download/v1.0.0/hid2hcix.exe" -OutFile "C:\hid2hcix.exe"

$trigger = New-JobTrigger -AtStartup -RandomDelay 00:00:30
Register-ScheduledJob -Trigger $trigger -FilePath C:\hid2hcix.exe -Name HID2HCI -Credential (Get-Credential)

