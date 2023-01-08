$vm1 = Get-VM -Name "VM1 - Ubuntu 22.04"
$vm2 = Get-VM -Name "VM2 - Windows 10"
$vm3 = Get-VM -Name "VM3 - Windows 7"
$vm4 = Get-VM -Name "VM4 - Mint 21.1"

Start-VM -VM $vm1
Start-VM -VM $vm2
Start-VM -VM $vm3
Start-VM -VM $vm4
