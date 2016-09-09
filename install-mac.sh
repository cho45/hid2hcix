#!/bin/sh
set -x

curl -L https://github.com/cho45/hid2hcix/releases/download/v1.0.0/hid2hcix -o /tmp/hid2hcix
sudo cp /tmp/hid2hcix /usr/local/bin/hid2hcix
sudo chmod +x /usr/local/bin/hid2hcix

curl -L https://raw.githubusercontent.com/cho45/hid2hcix/master/etc/net.lowreal.hid2hcix.plist -o /tmp/net.lowreal.hid2hcix.plist
sudo cp /tmp/net.lowreal.hid2hcix.plist /System/Library/LaunchDaemons/net.lowreal.hid2hcix.plist
sudo launchctl load /System/Library/LaunchDaemons/net.lowreal.hid2hcix.plist

