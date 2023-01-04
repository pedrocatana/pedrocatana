$vm1 = Get-VM -Name "VM1" // Definir a máquina 1 como $vm1
$vm2 = Get-VM -Name "VM2" // Definir a máquina 2 como $vm2
$vm3 = Get-VM -Name "VM3" // Definir a máquina 3 como $vm3
$vm4 = Get-VM -Name "VM4" // Definir a máquina 4 como $vm4


Start-VM -VM $vm1 // Iniciar a VM1
Start-VM -VM $vm2 // Iniciar a VM2
Start-VM -VM $vm3 // Iniciar a VM3
Start-VM -VM $vm4 // Iniciar a VM4
