//Fansoli Ibnu Mustafa 2411500362
//Puteri Jasmine Salsabila 2411501121
//Gita Shafira 2411502178
//Muhammad Razin Haidar Karim 2411500016

#include <iostream>
#include <stdio.h>
#include <stdbool.h>

int n = -1;
int pilih, front = 0, rear = -1, x;
int l[1000];
bool menu = true;

void panjang(){
	if(n<0){
		bool retry = true;
		char cont;
		while(retry){
			printf("Panjang Antrian: "); scanf("%i", &n);
			if(n<1){
				printf("Antrian harus memiliki nilai setidaknya 1.\n\n");
			}else{
				printf("Panjang Antrian adalah %i. Anda tidak dapat mengubahnya kembali, apakah anda yakin? (Y untuk lanjut): ",n); scanf(" %c", &cont);
				if(cont == 'Y'){
					printf("Panjang dari antrian telah berhasil diperbarui menjadi %i.",n);
					retry = false;
				}
			}
		}	
	} else{
		printf("Panjang Antrian sudah diisi sebelumnya dan tidak dapat diubah kembali.");
	}
}

void tambah(){
	if(rear!=n-1){
		bool repeat = true;
		char cont;
		while(repeat && rear<n-1){
			rear++;
			printf("Masukkan nilai yang akan di-insert pada baris ke-%i: ",rear); scanf("%i", &x);
			l[rear] = x;
			printf("Antrian telah berhasil ditambahkan.\nLanjut mengisi? (Y untuk lanjut): "); scanf(" %c",&cont);
			if(cont!='Y'){
				repeat = false;
			}
		}
		repeat = false;
	}else{
		printf("Antrian telah penuh, tidak dapat menambahkan lagi.");
	}
}

void hapus(){
	if(front<rear+1){
		bool repeat = true;
		char cont;
		while(repeat){
			if(front==rear+1 && rear==n-1){
				printf("\n=========================================\nSemua antrian telah berhasil dihapus, dan tidak ada lagi antrian yang dapat ditambahkan.\nSistem antrian telah di-reset!");
				front = 0;
				rear = -1;
				repeat = false;
			}else if(front<rear+1){
				printf("Anda yakin ingin menghapus antrian ke-%i? (Y untuk lanjut): ",front); scanf(" %c",&cont);
				if(cont=='Y'){
					x = l[front];
					printf("Antrian ke-%i telah berhasil dihapus. Isi antrian: %i.\n\n",front,l[front]);
					front++;
				}else{
					repeat = false;
				}
			}else{
				repeat = false;
			}
		}
	} else {
		printf("Tidak ada antrian yang dapat dihapus.");
	}
}

void lihat(){
	int view = 0, jum = 0;
	if(front<rear+1){
		while(view<n){
			if(view>=front && view<=rear){
				printf("Antrian ke-%i: %i\n",view,l[view]);
				jum++;
			}
			view++;
		}
		printf("Total antrian yang terisi: %i",jum);
	}else{
		printf("Antrian belum terisi.");
	}
}

void keluar(){
	printf("Sampai jumpa!");
	menu = false;
}

int main(){
	while(menu){
		printf("\n\n=========================================\n\t\t  Menu\n=========================================\n1. Tentukan Panjang Antrian\n2. Insert Linear Queue\n3. Delete Linear Queue\n4. Tampil Linear Queue\n5. Keluar");
		printf("\n=========================================\nPilih Isi Menu: "); scanf("%i", &pilih);
		printf("=========================================\n");
		if(pilih==1){
			panjang();
		} else if(pilih > 1 && pilih < 6){
			if(n>0){
				if(pilih == 2){
					tambah();
				}else if(pilih == 3){
					hapus();
				}else if(pilih==4){
					lihat();
				}else if(pilih==5){
					keluar();
				}
			}else{
				printf("Masukkan dulu panjang antrian.");
			}
		}else {
			printf("Angka yang anda input tidak terdaftar di dalam Menu. Harap coba kembali.\n");
		}
	}
}
