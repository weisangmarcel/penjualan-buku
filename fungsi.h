//Struct untuk Laporan buku
typedef struct{
	int hari;
	int bulan;
	int tahun;
	char *judul[20];
	char *nama_pelanggan[20];
	char *jenis_buku[20];
	char *nama_buku[20];
	int jumlah_buku;
	int harga_buku;
	int total_pembayaran;
} Buku;

//struct untuk pembelian buku

void welcome(){
	printf("----------------------------------------------------------\n");
	printf("*---- Selamat Datang Di Aplikasi Penjualan Buku ----*");
	printf("\n----------------------------------------------------------\n");
}

void option(){
	printf("Mau Ngapain:\n\n");
	//Opsi Menu
	printf("[1] Menjual Buku\n[2] Cetak Laporan Buku Berdasarkan Tanggal Transaksi\n[3] Cetak Laporan Buku Berdasarkan Penjualan Terbanyak");
}

void verif_opsi(int a, int *os, int *condition){
	//looping dengan pesan error
	while(a>3 || a<1){
		system("cls");
		welcome();
		printf("Error: Tidak ada opsi dengan pilihan \"%d\"\n",a);
		option();
		printf("\n");
		scanf("%d", &a);
	}
	//kasih pointer value
	*os = a;
	*condition = 1;
}

void cetak_laporan_buku(int b){
	char buffer[100], tulisan[30];
	char tmp2[20];
    int i, j, tmp;
	int jumlah_data, a;
	
	system("cls");
	
	printf("------------------------------------------------------------------------------------------------------------------------------------------------------\n");
	printf("*----------------------------------------------------- Cetak Penjualan Buku --------------------------------------------------------------------------*\n\n");
	
	FILE *file = fopen("sales.txt","r");
	
	fscanf(file, "%s %d", &tulisan, &jumlah_data);
	Buku *isi = malloc(sizeof(Buku) * jumlah_data);
	
//	skip 2 line pertama
	fgets(buffer, 100, file);
	fgets(buffer, 100, file);
	
	printf("No\tTanggal Transaksi\tNama Pelanggan\t\tJenis Buku\tNama Buku\t\tJumlah Buku\tHarga Buku\tTotal Pembayaran\n\n");
	
	//mengambil data lama
	for(a = 0; a<jumlah_data; a++){
		fscanf(file, "%d-%d-%d %s %s %s %d %d %d", &isi[a].hari, &isi[a].bulan, &isi[a].tahun, &isi[a].nama_pelanggan, &isi[a].jenis_buku, &isi[a].nama_buku, &isi[a].jumlah_buku, &isi[a].harga_buku, &isi[a].total_pembayaran);	
	}
	
	if(b == 3){
		//urutkan bedasarkan jumlah terbanyak
		for(i=0; i<jumlah_data; i++)
	    {
	        for(j=i+1; j<jumlah_data; j++)
	        {
	            if(isi[i].jumlah_buku < isi[j].jumlah_buku)
	            {	
	            	//jumlah buku
	                tmp = isi[i].jumlah_buku;
	                isi[i].jumlah_buku = isi[j].jumlah_buku;
	                isi[j].jumlah_buku = tmp;
	                
	                //hari
	                tmp = isi[i].hari;
	                isi[i].hari = isi[j].hari;
	                isi[j].hari = tmp;
	                
	                //bulan
	                tmp = isi[i].bulan;
	                isi[i].bulan = isi[j].bulan;
	                isi[j].bulan = tmp;
	                
	                //tahun
	                tmp = isi[i].tahun;
	                isi[i].tahun = isi[j].tahun;
	                isi[j].tahun = tmp;
	                
	                //nama pelanggan
	                strcpy(tmp2, isi[i].nama_pelanggan);
	                strcpy(isi[i].nama_pelanggan, isi[j].nama_pelanggan);
	                strcpy(isi[j].nama_pelanggan, tmp2);
	                
					//jenis buku
	                strcpy(tmp2, isi[i].jenis_buku);
	                strcpy(isi[i].jenis_buku, isi[j].jenis_buku);
	                strcpy(isi[j].jenis_buku, tmp2);
	
					//nama buku
	                strcpy(tmp2, isi[i].nama_buku);
	                strcpy(isi[i].nama_buku, isi[j].nama_buku);
	                strcpy(isi[j].nama_buku, tmp2);
	  
	                //harga buku
	                tmp = isi[i].harga_buku;
	                isi[i].harga_buku = isi[j].harga_buku;
	                isi[j].harga_buku = tmp;
	                
	                //total pembayaran
	                tmp = isi[i].total_pembayaran;
	                isi[i].total_pembayaran = isi[j].total_pembayaran;
	                isi[j].total_pembayaran = tmp;
	                
	            }
	        }
	    }
    }else{
    	//Urutkan bedasarkan tanggal
    	//tahun
    	for(i=0; i<jumlah_data; i++)
	    {
	        for(j=i+1; j<jumlah_data; j++)
	        {
	            if(isi[i].tahun < isi[j].tahun)
	            {	
	            	//jumlah buku
	                tmp = isi[i].jumlah_buku;
	                isi[i].jumlah_buku = isi[j].jumlah_buku;
	                isi[j].jumlah_buku = tmp;
	                
	                //hari
	                tmp = isi[i].hari;
	                isi[i].hari = isi[j].hari;
	                isi[j].hari = tmp;
	                
	                //bulan
	                tmp = isi[i].bulan;
	                isi[i].bulan = isi[j].bulan;
	                isi[j].bulan = tmp;
	                
	                //tahun
	                tmp = isi[i].tahun;
	                isi[i].tahun = isi[j].tahun;
	                isi[j].tahun = tmp;
	                
	                //nama pelanggan
	                strcpy(tmp2, isi[i].nama_pelanggan);
	                strcpy(isi[i].nama_pelanggan, isi[j].nama_pelanggan);
	                strcpy(isi[j].nama_pelanggan, tmp2);
	                
					//jenis buku
	                strcpy(tmp2, isi[i].jenis_buku);
	                strcpy(isi[i].jenis_buku, isi[j].jenis_buku);
	                strcpy(isi[j].jenis_buku, tmp2);
	
					//nama buku
	                strcpy(tmp2, isi[i].nama_buku);
	                strcpy(isi[i].nama_buku, isi[j].nama_buku);
	                strcpy(isi[j].nama_buku, tmp2);
	  
	                //harga buku
	                tmp = isi[i].harga_buku;
	                isi[i].harga_buku = isi[j].harga_buku;
	                isi[j].harga_buku = tmp;
	                
	                //total pembayaran
	                tmp = isi[i].total_pembayaran;
	                isi[i].total_pembayaran = isi[j].total_pembayaran;
	                isi[j].total_pembayaran = tmp;
	                
	            }
	        }
	    }
	    
	    //bulan
	    for(i=0; i<jumlah_data; i++)
	    {
	        for(j=i+1; j<jumlah_data; j++)
	        {
	            if(isi[i].tahun == isi[j].tahun && isi[i].bulan<isi[j].bulan)
	            {	
	            	//jumlah buku
	                tmp = isi[i].jumlah_buku;
	                isi[i].jumlah_buku = isi[j].jumlah_buku;
	                isi[j].jumlah_buku = tmp;
	                
	                //hari
	                tmp = isi[i].hari;
	                isi[i].hari = isi[j].hari;
	                isi[j].hari = tmp;
	                
	                //bulan
	                tmp = isi[i].bulan;
	                isi[i].bulan = isi[j].bulan;
	                isi[j].bulan = tmp;
	                
	                //tahun
	                tmp = isi[i].tahun;
	                isi[i].tahun = isi[j].tahun;
	                isi[j].tahun = tmp;
	                
	                //nama pelanggan
	                strcpy(tmp2, isi[i].nama_pelanggan);
	                strcpy(isi[i].nama_pelanggan, isi[j].nama_pelanggan);
	                strcpy(isi[j].nama_pelanggan, tmp2);
	                
					//jenis buku
	                strcpy(tmp2, isi[i].jenis_buku);
	                strcpy(isi[i].jenis_buku, isi[j].jenis_buku);
	                strcpy(isi[j].jenis_buku, tmp2);
	
					//nama buku
	                strcpy(tmp2, isi[i].nama_buku);
	                strcpy(isi[i].nama_buku, isi[j].nama_buku);
	                strcpy(isi[j].nama_buku, tmp2);
	  
	                //harga buku
	                tmp = isi[i].harga_buku;
	                isi[i].harga_buku = isi[j].harga_buku;
	                isi[j].harga_buku = tmp;
	                
	                //total pembayaran
	                tmp = isi[i].total_pembayaran;
	                isi[i].total_pembayaran = isi[j].total_pembayaran;
	                isi[j].total_pembayaran = tmp;
	                
	            }
	        }
	    }
	    
	    //hari
	    for(i=0; i<jumlah_data; i++)
	    {
	        for(j=i+1; j<jumlah_data; j++)
	        {
	            if(isi[i].tahun == isi[j].tahun && isi[i].bulan == isi[j].bulan && isi[i].hari < isi[j].hari)
	            {	
	            	//jumlah buku
	                tmp = isi[i].jumlah_buku;
	                isi[i].jumlah_buku = isi[j].jumlah_buku;
	                isi[j].jumlah_buku = tmp;
	                
	                //hari
	                tmp = isi[i].hari;
	                isi[i].hari = isi[j].hari;
	                isi[j].hari = tmp;
	                
	                //bulan
	                tmp = isi[i].bulan;
	                isi[i].bulan = isi[j].bulan;
	                isi[j].bulan = tmp;
	                
	                //tahun
	                tmp = isi[i].tahun;
	                isi[i].tahun = isi[j].tahun;
	                isi[j].tahun = tmp;
	                
	                //nama pelanggan
	                strcpy(tmp2, isi[i].nama_pelanggan);
	                strcpy(isi[i].nama_pelanggan, isi[j].nama_pelanggan);
	                strcpy(isi[j].nama_pelanggan, tmp2);
	                
					//jenis buku
	                strcpy(tmp2, isi[i].jenis_buku);
	                strcpy(isi[i].jenis_buku, isi[j].jenis_buku);
	                strcpy(isi[j].jenis_buku, tmp2);
	
					//nama buku
	                strcpy(tmp2, isi[i].nama_buku);
	                strcpy(isi[i].nama_buku, isi[j].nama_buku);
	                strcpy(isi[j].nama_buku, tmp2);
	  
	                //harga buku
	                tmp = isi[i].harga_buku;
	                isi[i].harga_buku = isi[j].harga_buku;
	                isi[j].harga_buku = tmp;
	                
	                //total pembayaran
	                tmp = isi[i].total_pembayaran;
	                isi[i].total_pembayaran = isi[j].total_pembayaran;
	                isi[j].total_pembayaran = tmp;
	            }
	        }
	    }
	}
		
	//final print table
	for(i=0; i<jumlah_data; i++){
		printf("%d\t%d-%d-%d\t\t%s\t\t\t%s\t\t%s\t\t%d\t\t%d\t         %d\n", i+1, isi[i].hari, isi[i].bulan, isi[i].tahun, isi[i].nama_pelanggan, isi[i].jenis_buku, isi[i].nama_buku, isi[i].jumlah_buku, isi[i].harga_buku, isi[i].total_pembayaran);
	}
	
	//Bersih"
    fclose(file);
    free(isi);

	printf("------------------------------------------------------------------------------------------------------------------------------------------------------\n");
}

//Halaman Pembelian buku 
void halaman_pembelian(){
	system("cls");
	int kode_buku, stop = 0, count = 1;
	int hari, bulan, tahun, arr_jumlah_buku[20], arr_harga_buku[20], total_pembayaran[20];
	char judul[20][20], nama_pelanggan[20][20], jenis_buku[20][20], nama_buku[20][20];
	
	while(stop == 0){
		printf("Silahkan pilih buku yang mau dibeli: (Buke Ke-%d)\n\n ", count);
	//	pilihan buku
		printf("No\tNama Buku\t\tJenis Buku\tHarga Buku\n");
		printf("1\tJournalism\t\tNoFiksi\t\t10000\n2\tBrontosaurus\t\tNoFiksi\t\t20000\n3\tSoekarno\t\tNoFiksi\t\t72500\n4\tKeberangkatan\t\tFiksi\t\t100000\n5\tNoblesse\t\tFiksi\t\t5000\n6\tEndessor\t\tFiksi\t\t25000");
		
		printf("\n\nSilahkan Pilih Kode buku yang ingin dibeli: ");
		scanf("%d", &kode_buku);
		
		//Proses pemebelian
		int harga_buku, jumlah_buku, a, jumlah_data_lama, jumlah_data_baru, i;	
		char lanjut;
	//	Tanggal hari ini
		time_t t = time(NULL);
	  	struct tm tm = *localtime(&t);
	  	
	// pemilihan kode buku
		switch(kode_buku){
			case 1:
				strcpy(nama_buku, "Journalism");
				strcpy(jenis_buku, "NoFiksi");
				harga_buku = 10000;
				break;
			case 2:
				strcpy(nama_buku, "Brontosaurus");
				strcpy(jenis_buku, "NoFiksi");
				harga_buku = 20000;
				break;
			case 3:
				strcpy(nama_buku, "Soekarno");
				strcpy(jenis_buku, "NoFiksi");
				harga_buku = 72500;
				break;
			case 4:
				strcpy(nama_buku, "Keberangkatan");
				strcpy(jenis_buku, "Fiksi");
				harga_buku = 100000;
				break;
			case 5:
				strcpy(nama_buku, "Noblesse");
				strcpy(jenis_buku, "Fiksi");
				harga_buku = 5000;
				break;
			case 6:
				strcpy(nama_buku, "Endessor");
				strcpy(jenis_buku, "Fiksi");
				harga_buku = 25000;
				break;
			default :
				printf("Terjadi Kesalahan");
				return 1;
		}
		
		printf("Jumlah buku yang mau dibeli: ");
		scanf("%d", &jumlah_buku);
		
		// penyimoanan data ke arr
		strcpy(judul[count], nama_buku);
		arr_jumlah_buku[count] = jumlah_buku;
		arr_harga_buku[count] = harga_buku;
		total_pembayaran[count] = jumlah_buku * harga_buku;
		strcpy(jenis_buku[count], jenis_buku);
		
		//konfirmasi kelanjutan beli buku
		printf("Mau Beli Buku Lagi(y/n) ? ");
		scanf(" %c", &lanjut);
		
		if(lanjut == 'n'){
			//tidak lanjut
			
			//input tanggal transaksi
			printf("Masukan tanggal transaksi (format : %02d-%02d-%d): ", tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900);
			scanf("%d-%d-%d", &hari, &bulan, &tahun);
			
			//input nama pelanggan
			printf("Masukan nama pelanggan: ");
			scanf("%s", &nama_pelanggan);
			char buffer[100], tulisan[30];
			
			//file satrt
			FILE *file_lama = fopen("sales.txt","r");
			FILE *file_baru = fopen("sales_temp.txt","w");

			fscanf(file_lama, "%s %d", &tulisan, &jumlah_data_lama);
			Buku *isi = malloc(sizeof(Buku) * jumlah_data_lama);
			
			//skip 2 line pertama
			fgets(buffer, 100, file_lama);
			fgets(buffer, 100, file_lama);
			
			//mengambil data lama
			for(a = 0; a<jumlah_data_lama; a++){
				fscanf(file_lama, "%d-%d-%d %s %s %s %d %d %d", &isi[a].hari, &isi[a].bulan, &isi[a].tahun, &isi[a].nama_pelanggan, &isi[a].jenis_buku, &isi[a].nama_buku, &isi[a].jumlah_buku, &isi[a].harga_buku, &isi[a].total_pembayaran);	
			}
			
			//print data lama ke file temp
			//jumlah data baru
			jumlah_data_baru = jumlah_data_lama+count;
			fprintf(file_baru ,"%s %d\n", tulisan, jumlah_data_baru);
			fprintf(file_baru, "Tanggal Transaksi\tNama Pelanggan\t\tJenis Buku\tNama Buku\t\tJumlah Buku\tHarga Buku\tTotal Pembayaran\n");
			for(i=0; i<jumlah_data_lama; i++){
				fprintf(file_baru ,"%d-%d-%d\t\t%s\t\t\t%s\t\t%s\t\t%d\t\t%d\t         %d\n", isi[i].hari, isi[i].bulan, isi[i].tahun, isi[i].nama_pelanggan, isi[i].jenis_buku, isi[i].nama_buku, isi[i].jumlah_buku, isi[i].harga_buku, isi[i].total_pembayaran);
			}
			
			//apend data baru
			for(i=1; i<=count; i++){	
				fprintf(file_baru ,"%d-%d-%d\t\t%s\t\t\t%s\t\t%s\t\t%d\t\t%d\t         %d\n", hari, bulan, tahun, nama_pelanggan, jenis_buku[i], judul[i], arr_jumlah_buku[i], arr_harga_buku[i], total_pembayaran[i]);
			}
			printf("%d %d", count, i);
			
			//stop looping
			stop = 1;
			
			//bersih"
			fclose(file_lama);
			fclose(file_baru);
			free(isi);
			
			//permainan file
			remove("sales.txt");
			rename("sales_temp.txt", "sales.txt");
			
			system("cls");
			printf("Data berhasil ditambahkan\n\n");
			
		}else{
			//lanjut
			system("cls");
			count+=1;
		}
	}
}


void pilih_opsi_menu(int os, int *stop){
	char la;
	switch(os){
		case 1:
			halaman_pembelian();
			break;
		case 2:
			cetak_laporan_buku(os);
			break;
		case 3:
			cetak_laporan_buku(os);
			break;
		default :
			printf("Terjadi Kesalahan");
			return 1;
			break;
	}
	
	printf("Kembali ke menu utama(y/n) ? ");
	scanf(" %c", &la);
	if(la == 'n'){
		*stop = 1;
	}else{
		system("cls");
	}
	
}

