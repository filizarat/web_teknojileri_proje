    class Kisi {
         
     char *satir;
     ArrayList <char> liste = new ArrayList <char>();
     Rastgele rs;
     KimlikNo kimlik;
     Telefon telefon;
     char *isim;
     int yas;

     void DosyaOku()
        {
            
            
            try
            {
                File dosya = new File("random_isimler.txt");
                BufferedReader oku = new BufferedReader(new InputStreamReader(new FileInputStream(dosya),"UTF8"));
           
                while((satir = oku.readLine())!=null)
                {
                    String dizi[] = satir.split(" ");
                    liste.add(satir);
                }
          
                int sayi=liste.size();// listenin uzunlugunu baktım
                int deger=(int) Math.abs(rs.rand()%3001);//3000 dahil oması için
                isim=(liste.get(deger));
                System.out.println("İSİM: "+isim);
                yas=(int) Math.abs(rs.rand()%100);
                System.out.println("YAŞ: "+yas);
          
                oku.close();
            }
            catch(Exception e)
            {
                System.err.println("Hata : "+e.getMessage());
            }
            //System.out.println(liste);
        }

        void IMEIKontrol(String IMEIdeger)
        {
            IMEINo ımeı=new IMEINo();
            ımeı.IMEINoKontrolet(IMEIdeger);
        }
        
        void KimlikKontrol(String tcdeger)
        {
            KimlikNo kimlik=new KimlikNo();
            kimlik.KimlikNoKontrol(tcdeger);
            
        }

        class Rastgele
    {
        private long a = 25214903917l;
        private long c = 11;
        private long previous = System.nanoTime();
    
        public long rand() //Random Sayı oluşturmak için bir fonksiyon
        {
        long r = a * previous + c;
        previous = r;
        return r;
        }
   
    }
    /********************************************/
    class KimlikNo
    {
        Rastgele rs=new Rastgele();
        int[] tc=new int[11];
        int yeni=0; 
    
        public void KimlikNoUret()
        {
            for(int i=0;i<9;i++)//tcnin ilk 9 hanesi için sayı ürettim 
            {
                tc[i]=(int) Math.abs(rs.rand()%10);
            }
        
            while(tc[0]==0)
            {
                tc[0]=(int) Math.abs(rs.rand()%10);
            }
            for(int j=0;j<=8;j+=2)//1 3 5 7 9 haneleri topladım
            {
                yeni=yeni+tc[j];
            }
            yeni=yeni*7;
            for(int k=1;k<=7;k+=2)
            {
                yeni=yeni-tc[k];
            }    
            yeni= yeni%10;
            tc[9]=yeni;
            yeni=0;
            for(int i=0;i<tc.length;i++)
            {
                yeni=yeni+tc[i];
            }
            yeni=yeni %10;
            tc[10]=yeni;
            yeni=0;
            System.out.print("TC: ");
            for(int i=0;i<tc.length;i++)
            {
                System.out.print(tc[i]);
            }
            System.out.println(" ");
        }
        
        public void KimlikNoKontrol(String tcdeger)
        {
            for(int i=0;i<11;i++)//tcnin ilk 9 hanesi için sayı ürettim 
            {
                tc[i] = Character.getNumericValue(tcdeger.charAt(i));
            }
            System.out.print("TC: ");
            for(int i=0;i<tc.length;i++)
            {
                System.out.print(tc[i]);
            }
             System.out.println(" ");
            for(int j=0;j<=8;j+=2)//1 3 5 7 9 haneleri topladım
            {
                yeni=yeni+tc[j];
            }
            yeni=yeni*7;
            for(int k=1;k<=7;k+=2)
            {
                yeni=yeni-tc[k];
            }  
            yeni= yeni%10;
            if(tc[9]==yeni)
            {
                yeni=0;
                for(int i=0;i<10;i++)
                {
                yeni=yeni+tc[i];
                }
                yeni=yeni %10;
                if(tc[10]==yeni)
                {
                    yeni=0;
                    System.out.print("Geçerli TC"+"\n");
                }
            }
            else
            {
                System.out.print("Geçersiz TC"+"\n");
            }
        }
    }
    /********************************************/
    class IMEINo
    {
        
        Rastgele rs=new Rastgele();
        int[] IMEI=new int[15]; 
        int yeni=0; 
    
        public void IMEINoUret()
        {
            for(int i=0;i<14;i++)//tcnin ilk 9 hanesi için sayı ürettim 
            {
                IMEI[i]=(int) Math.abs(rs.rand()%10);
            }
            
            for(int i=0;i<=12;i+=2)
            {
                yeni=yeni+ IMEI[i];
            }
            for(int j=1;j<=13;j+=2)
            {
                int a=IMEI[j]*2;
                if(a>=10)
                {
                    yeni=yeni+a%10;
                    yeni=yeni+1;
                }
                else
                {
                  yeni=yeni+a;
                }    
             } 
            double number=yeni;
            if((yeni %10)!=0)
            {
               number = Math.round((yeni + 5)/ 10.0) * 10.0;
            }
            number=number-yeni;
            IMEI[14]=(int)number;
            System.out.print("IMEI: ");
            for(int i=0;i<IMEI.length;i++)
            {
                System.out.print(IMEI[i]);
            }
            System.out.println(" ");
        }
    
        public void IMEINoKontrolet(String IMEIdeger)
        {
            for(int i=0;i<15;i++) 
            {
                IMEI[i] = Character.getNumericValue(IMEIdeger.charAt(i));
            }
            System.out.print("IMEI: ");
            for(int i=0;i<IMEI.length;i++)
            {
                System.out.print(IMEI[i]);
            }
             System.out.println(" ");
             for(int i=0;i<=12;i+=2)
            {
                yeni=yeni+ IMEI[i];
            }
             for(int j=1;j<=13;j+=2)
            {
                int a=IMEI[j]*2;
                if(a>=10)
                {
                    yeni=yeni+a%10;
                    yeni=yeni+1;
                }
                else
                {
                  yeni=yeni+a;
                }    
             }
             double number=yeni;
            if((yeni %10)!=0)
            {
               number = Math.round((yeni + 5)/ 10.0) * 10.0;
            }
            number=number-yeni;
            if(IMEI[14]==(int)number)
            {
                System.out.print("Geçerli IMEI"+"\n");
            }
            else
            {
                System.out.print("Geçersiz IMEI"+"\n");
            }
            System.out.print("IMEI: ");
            for(int i=0;i<IMEI.length;i++)
            {
                System.out.print(IMEI[i]);
            }
        }
    }

    class Telefon
    {
        
        Rastgele rs=new Rastgele();
        int[] telefon=new int[11];
        
        public void TelefonUret()
        {
           telefon[0]=0;
           telefon[1]=5;
           for(int i=2 ;i<=10;i++)
           {
               telefon[i]=(int) Math.abs(rs.rand()%10); 
           }
           System.out.print("TELEFON: ");
           for(int i=0;i<telefon.length;i++)
           {
                System.out.print(telefon[i]);
           }
        }
    
    }

     }