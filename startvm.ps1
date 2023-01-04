# Iniciar as máquinas virtuais

$vm1 = Get-VM -Name "VM1"
$vm2 = Get-VM -Name "VM2"
$vm3 = Get-VM -Name "VM3"
$vm4 = Get-VM -Name "VM4"

Start-VM -VM $vm1
Start-VM -VM $vm2
Start-VM -VM $vm3
Start-VM -VM $vm4
