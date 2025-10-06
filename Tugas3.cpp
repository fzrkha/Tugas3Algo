#include <iostream>
#include <stdio.h>
#include <stdbool.h>

int main(){
	int n = -1;
	int pilih, front, rear;
	char satu;
	bool start = true, panjang;
	while(start){
		printf("\n\n=========================================\n\t\t  Menu\n=========================================\n1. Tentukan Panjang Antrian\n2. Insert Linear Queue\n3. Delete Linear Queue\n4. Tampil Linear Queue\n5. Keluar");
		printf("\n=========================================\nPilih Isi Menu: "); scanf("%i", &pilih);
		printf("=========================================\n");
		if(pilih==1){
			if(n<0){
				start = false;
				panjang = true;
				while(panjang){
					printf("Panjang Antrian: "); scanf("%i", &n);
					printf("Panjang Antrian adalah %i. Anda tidak dapat mengubahnya kembali, yakin? (Y untuk lanjut): ",n); scanf(" %c", &satu);
					if(satu == 'Y'){
						int l[n];
						printf("Panjang dari antrian telah berhasil diperbarui menjadi %i.",n);
						panjang = false;
						start = true;
					}
				}	
			} else{
				printf("Antrian sudah diisi sebelumnya dan tidak dapat diubah kembali.");
			}
		} else if(pilih > 1 && pilih < 6){
			if(n>=0){
				printf("Y");
			}else{
				printf("Mohon masukkan dulu panjangnya!");
			}
		} else {
			printf("Masukkan angka yang btul oi!\n");
		}
	}
}
