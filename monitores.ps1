$vmCount = 4
$monitorCount = 4


$vm1 = Get-VM -Name "VM1 - Ubuntu 22.04" | Select-Object -First $vmCount
$vm2 = Get-VM -Name "VM2 - Windows 10" | Select-Object -First $vmCount
$vm3 = Get-VM -Name "VM3 - Windows 7" | Select-Object -First $vmCount
$vm4 = Get-VM -Name "VM4 - Mint 21.1" | Select-Object -First $vmCount

$monitor1 = 1..$monitorCount
$monitor2 = 2..$monitorCount
$monitor3 = 3..$monitorCount
$monitor4 = 4..$monitorCount


foreach ($vm in $vms) {
  $monitor = $monitors | Select-Object -First 2

  Start-VM -VM $vm -Monitor $monitor

  $monitors = $monitors | Select-Object -Skip 1
}