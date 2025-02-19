//#include <iostream>
//#include <math.h>
//#include <conio.h>
//#include <string>
//#include <fstream>
//#include <iomanip>
//
//using namespace std;
//
//string parsr_per(string p)
//{
//	string vz="      ", mes="";
//	int pos;
//	pos = p.find(" ");
//	if (pos >= 0)
//	{
//		vz = p.substr(pos+1, 4);
//		mes = p.substr(0, pos);
//		if (mes =="Январь")  //кодировка?...
//		{
//			vz = "01" + vz;
//		}
//	}
//	return vz;
//}
//
//bool o_digit(char p)
//{
//	bool vz = false;
//	if (p>47 && p<58)
//	{
//		vz = true;
//	}
//	return vz;
//}
//
//class U_cena
//{
//private:
//	double cena;
//	double prihod;
//	double rashod;
//	double ostatok;
//public:
//	U_cena() 
//	{ 
//		cena = 0; 
//		prihod = 0; 
//		rashod = 0; 
//		ostatok = 0; 
//	};
//	U_cena(string p) 
//	{
//		int pos;
//		string t;
//		if (p.length() >= 92)
//		{
//			pos = p.find("|");
//			p = p.substr(pos + 1);
//			pos = p.find("|");
//			t = p.substr(0, pos + 1);
//			cena = atof(t.c_str());
//
//			p = p.substr( pos + 1);
//			pos = p.find("|");
//			t = p.substr(0, pos + 1);
//			prihod = atof(t.c_str());
//
//			//p = p.substr(0, pos + 1);   ???
//			pos = p.find("|");
//			t = p.substr(0, pos + 1);
//			rashod = atof(t.c_str());
//
//			//p = p.substr(0, pos + 1);   ???
//			pos = p.find("|");
//			t = p.substr(0, pos + 1);
//			ostatok = atof(t.c_str());
//		}
//		else
//		{
//			cena = 0;
//			prihod = 0;
//			rashod = 0;
//			ostatok = 0;
//		}
//
//	};
//	U_cena(const U_cena& o) 
//	{ 
//		cena = o.cena; 
//		prihod = o.prihod; 
//		rashod = o.rashod; 
//		ostatok = o.ostatok;
//	};
//	~U_cena() {};
//
//
//	void print() 
//	{
//		cout << cena << "  " << prihod << "  " << cena * prihod << "  " << rashod << "  " << cena * rashod << "  " << ostatok << cena * ostatok << endl;
//	};
//
//	U_cena* getOb() 
//	{
//		return this;
//	}
//};
//
//
//class material
//{
//private:
//	string kod;
//	string nazv;
//	string ed_izm;
//	int Nmax;
//	int n;
//	U_cena** Mc;
//
//public:
//	material() { 
//		kod = "      "; 
//		nazv = "No naz"; 
//		ed_izm = "None"; 
//		n = 0; 
//		Nmax = 20; 
//		Mc = new U_cena * [Nmax];
//	};
//	material(string p) 
//	{
//		if (p.length() > 47)
//		{
//			kod = p.substr(0, 6);
//			nazv = p.substr(8, 30);
//			ed_izm = p.substr(41, 8);
//		}
//		else
//		{
//			kod = "      ";
//			nazv = "No naz";
//			ed_izm = "None";
//		}
//		Nmax = 50;
//		n = 0;
//		Mc = new U_cena * [Nmax];
//	};
//
//	material(const material &o) 
//	{
//		kod = o.kod;
//		nazv = o.nazv;
//		ed_izm = o.ed_izm;
//		Nmax = o.Nmax;
//		n = o.n;
//		Mc = new U_cena * [Nmax];
//		if (n > 0)
//			for (int i = 0; i < n; i++)
//			{
//				Mc[i] = new U_cena(*o.Mc[i+1]->getOb()); //доб. мет. через конструктор копии cena//
//			}
//	};
//
//	~material() 
//	{
//		if (n > 0)
//			for (int i = 0; i < n; i++)
//				delete Mc[i];
//		delete[]Mc;
//	};
//
//	U_cena* getCena(int nom)
//	{
//		if (nom > 0 && nom<=n)
//		{
//			return Mc[nom - 1]->getOb();
//			cout << "Выход за границы";
//			_getch();
//			exit (1);
//		}
//	}
//	material* getOb() 
//	{
//		return this;
//	}
//
//	void print()
//	{
//		cout << kod << "" << nazv << " " << ed_izm << " (" << n << "/" << Nmax << ")\n";
//		if (n > 0)
//		{
//			for (int i = 0; i < n; i++)
//			{
//				Mc[i]->print();
//			}
//		}
//	}
//
//	void add_cena(U_cena& tmp)
//	{
//		if (n < Nmax)
//		{
//			Mc[n] = new U_cena(tmp);
//			n++;
//		}
//	}
//
//};
//
//class bal_schet
//{
//private:
//	string nomerBs;  //артикул + название(материалы)
//	int Nmax;
//	int n;
//	material** Mm;
//
//public:
//
//	bal_schet() { nomerBs = "No schet"; Nmax = 10; n = 0; Mm = new material * [Nmax]; };
//	bal_schet(string p_nom) { nomerBs = p_nom; Nmax = 10; n = 0; Mm = new material * [Nmax]; };
//	bal_schet(const bal_schet& o) 
//	{
//		nomerBs = o.nomerBs;
//		Nmax = o.Nmax;
//		n = o.n;
//		Mm = new material * [Nmax];
//		if (n > 0)
//			for (int i = 0; i < n; i++)
//			{
//				Mm[i] = new material(*o.Mm[i + 1]->getOb()); //доб. мет. через конструктор копии бал. счета
//			}
//	};
//
//	~bal_schet() 
//	{
//		if (n > 0)
//			for (int i = 0; i < n; i++)
//				delete Mm[i];
//		delete[]Mm;
//	};
//
//	material* getMat(int nom)
//	{
//		if (nom > 0 && nom <= n) return Mm[nom - 1]->getOb();
//	}
//
//	bal_schet* getOb() { return this; }
//
//	void print()
//	{
//		cout << nomerBs << " (" << n << "/" << Nmax << ")\n";
//		if(n>0)
//			for (int i = 0; i < n; i++)
//			{
//				Mm[i]->print();
//			}
//	}
//
//
//	string getNBs()
//	{
//		return nomerBs;
//	}
//
//	int add_mat(material& tmp)
//	{	
//		int vz = -1;
//		if (n < Nmax)
//		{
//			Mm[n] = new material(tmp);
//			vz = n;
//			n++;
//		}
//		return vz;
//	}
//
//	void  add_cena_mat(U_cena& tmp, int ind_mat)
//	{
//		int vz = -1;
//		if (ind_mat >= 0 && ind_mat < Nmax)
//		{
//			Mm[ind_mat]->add_cena(tmp);
//		}
//	}
//
//};
//
//class sklad
//{
//private:
//	string nazv;
//	int Nmax;
//	int n;
//	bal_schet** Mb;
//public:
//
//	sklad() { nazv = "No sklad"; Nmax = 10; n = 0; Mb = new bal_schet * [Nmax]; };
//	sklad(string n_Nazv) { nazv = n_Nazv; Nmax = 10; n = 0; Mb = new bal_schet * [Nmax]; };
//	sklad(const sklad &o) 
//	{
//		nazv = o.nazv;
//		Nmax = o.Nmax;
//		n = o.n;
//		Mb = new bal_schet * [Nmax];
//		if (n > 0)
//			for (int i = 0; i < n; i++)
//			{
//				Mb[i] = new bal_schet(*o.Mb[i+1]->getOb()); //доб. мет. через конструктор копии бал. счета
//			}
//	
//	};
//	~sklad() 
//	{
//		if (n > 0)
//			for (int i = 0; i < n; i++)
//				delete Mb[i];
//		delete[]Mb;
//	};
//
//	sklad* getOb() { return this; }
//
//	void print()
//	{
//		cout << nazv <<"("<<Nmax <<")" << endl;
//		if (n > 0)
//		{
//			for (int i = 0; i < n; i++)
//			{
//				Mb[i]->print();  //
//			}
//		}
//	}
//
//	string getNazv()
//	{
//		return nazv;
//	}
//
//	int find_Bs( string p)
//	{
//		int vz = -1;
//		if (n > 0)
//		{
//			for (int i = 0; i < n; i++)
//			{
//				if (Mb[i]->getNBs() == p)
//					vz = i; break;
//			}
//		}
//		return vz;
//	}
//
//
//
//	int add_Bs(bal_schet&o)
//	{
//		int vz = -1;
//		if (n<Nmax)
//		{
//			Mb[n] = new bal_schet(o);
//			vz = n;
//			n++;
//		}
//		return vz;
//	}
//
//	int  add_material_bl_s(material& tmp, int ind)
//	{
//		int vz = -1;
//		if (ind >= 0 && ind < Nmax)
//		{
//			vz=Mb[ind]->add_mat(tmp);
//		}
//		return vz;
//	}
//	void  add_cena_mat_bl(U_cena& tmp, int ind_bs, int ind_mat)
//	{
//		int vz = -1;
//		if (ind_bs >= 0 && ind_bs < Nmax)
//		{
//			Mb[ind_bs]->add_cena_mat(tmp, ind_mat);
//		}
//	}
//};
//
//class dok
//{
//private:
//	string N_per;  //месяц год - название
//	string per; //ммгггг
//	int Nmax;
//	int n;
//	sklad** Ms;
//
//public:
//
//	dok()
//	{
//		N_per = "Net perioda";
//		per = "      ";
//		Nmax = 20;
//		n = 0;  //тек кол-во склвдов
//		Ms = new sklad * [Nmax];
//	}
//
//	dok(const dok& o)
//	{
//		N_per = o.N_per;
//		per = o.per;
//		Nmax = o.Nmax;
//		n = o.n;
//		Ms = new sklad * [Nmax];
//		if(n>0)
//			for (int i = 0; i < n; i++)
//			{
//				Ms[i] = new sklad(*o.Ms[i]->getOb()); //доб. мет. getobj
//			}
//	}
//
//	dok(string f_name)
//	{
//		ifstream f(f_name);
//		string a;
//		Ms = new sklad * [Nmax];
//		if(f.is_open())
//		{ 
//			int fl=0, i=0, pos, i_skl, i_bs, i_mat;
//			string p, z, n_skl="", n_bs="";
//			while (!f.eof())
//			{
//				getline(f, p);
//				i++;
//				//cout << p << endl;
//				pos = p.find("->");
//				if (pos>=0)
//				{
//					n_skl = p.substr(30, pos-47);//-30-17
//					n_bs = p.substr(pos + 2);
//					//cout << n_skl <<"  " << n_bs << endl;
//					i_skl = find(n_skl);
//					if (i_skl < 0)
//					{
//						Ms[n] = new sklad(n_skl);
//						i_skl = n;
//						n++;
//						//sklad tmp(n_skl);
//						//sklad tmp = new sklad(n_skl);
//						
//					}
//					i_bs = find_S_Bs(i_skl, n_bs);
//					if (i_bs < 0)
//					{
//						bal_schet tmp(n_bs);
//						i_bs = Ms[i_skl]->add_Bs(tmp);
//					}
//					if (fl == 0)
//					{
//
//						getline(f, p);
//						N_per = p.substr(33);
//						fl = 1;
//						per = parsr_per(N_per);
//					}
//				}
//				else
//				{
//					if (p.length()>50)
//					{
//						z = p.substr(0, 4).c_str();
//						if ((z== "    ") && (o_digit(p[4]) == true))
//						p = p.substr(4);
//						material tmp(p);
//						i_mat=Ms[i_skl]->add_material_bl_s(tmp, i_bs);
//					}
//					else
//					{
//						if (p.length() > 92)
//						{
//							if (p[2] == '|' && (p[12] == '.' || p[24] == '.' || p[49] == '.' || p[74] == '.'))
//							{
//								U_cena tmpCena(p);
//								Ms[i_skl]->add_cena_mat_bl(tmpCena, i_bs, i_mat);
//
//							}
//						}
//					}
//				}
//
//			}
//		}
//		else
//		{
//			N_per = "Net perioda";
//		}
//	}
//
//	~dok()
//	{
//		if (n > 0)
//			for (int i = 0; i < n; i++)
//				delete Ms[i];
//		delete[]Ms;
//	}
//
//	void print()
//	{
//		cout << "\n" << N_per << "  " << per << "  (" << n << "/" << Nmax << ")" << endl;
//		if (n > 0)
//		{
//			for (int i = 0; i < n; i++)
//			{
//				Ms[i]->print();  //
//			}
//		}
//	
//	}
//
//	int find(string p)
//	{
//		int vz = -1;
//		if (n>0)
//		{
//			for (int i = 0; i < n; i++)
//			{
//				if (Ms[i]->getNazv()==p)
//				{
//					vz = i; break;
//				}
//
//			}
//		}
//		return vz;
//	}
//
//	int find_S_Bs(int ind, string p) /////////////////
//	{
//		int vz = -1;
//		if (ind >= 0 && ind < n)
//		{
//			vz = Ms[ind]->find_Bs(p);
//		}
//		return vz;
//	}
//
//};
//
//
//
//int main()
//{
//	setlocale(LC_ALL, "866");
//	dok a("d://sklad010.txt");
//	a.print();
//
//	_getch();
//}
//пример Полякова

//моя лаба
//#include <iostream>
//#include <math.h>
//#include <conio.h>
//#include <string>
//#include <fstream>
//#include <iomanip>
//#include <locale>
//#include <windows.h>
//
//using namespace std;
//
////string pars_per(string p)
////{
////	string vz="      ", mes="";
////	int pos;
////	pos = p.find(" ");
////	if (pos >= 0)
////	{
////		vz = p.substr(pos+1, 4);
////		mes = p.substr(0, pos);
////		if (mes =="Январь")  //кодировка?...
////		{
////			vz = "01" + vz;
////		}
////	}
////	return vz;
////}
//
//bool o_digit(char p)
//{
//	bool vz = false;
//	if (p>47 && p<58)
//	{vz = true;}
//	return vz;
//}
//
//class imusch
//{
//private:
//	int NomInvKart;
//	int InvNomer;
//	string Nazv;
//	int debZatr;
//	string dateVvod;
//	double balPrice;
//	double sumAmort;
//	double nakop;
//
//
//public:
//	imusch() 
//	{
//		NomInvKart = 0;          InvNomer = 0; 
//		Nazv = "NoNazv";         debZatr = 0; 
//		dateVvod = "00/0000";    balPrice = 0; 
//		sumAmort = 0;            nakop = 0;
//	}; 
//	imusch(string p) 
//	{
//
//		if (p.length() > 50)
//		{
//			int pos=0;
//			NomInvKart = atoi(p.substr(0,6).c_str());
//			InvNomer = atoi(p.substr(7, 7).c_str());
//			Nazv = p.substr(13, 49);
//
//			pos = p.find("/1");
//			if(pos<3)pos = p.find("/2");
//				debZatr = atoi(p.substr(pos - 5, 2).c_str());
//				dateVvod = p.substr(pos - 2, 7);
//				balPrice = atof(p.substr(pos + 5, 15).c_str());
//				sumAmort = atof(p.substr(pos + 20, 12).c_str());
//				nakop = atof(p.substr(pos + 32, 14).c_str());
//			
//		}
//		else
//		{
//			NomInvKart = 0;          InvNomer = 0;
//			Nazv = "NoNazv";         debZatr = 0;
//			dateVvod = "00/0000";    balPrice = 0;
//			sumAmort = 0;            nakop = 0;
//		}
//	};
//	~imusch() {};
//
//	imusch(imusch& o)
//	{
//
//		NomInvKart = o.NomInvKart;
//		InvNomer = o.InvNomer;
//		Nazv = o.Nazv;
//		debZatr = o.debZatr;
//		dateVvod = o.dateVvod;
//		balPrice = o.balPrice;
//		sumAmort = o.sumAmort;
//		nakop = o.nakop;
//	}
//	void print()
//	{
//		cout << " >";
//		cout.width(6);
//		cout << NomInvKart;
//		cout.width(6);
//		cout << InvNomer;
//		cout << Nazv;
//		cout.width(2);
//		cout << debZatr;
//		cout.width(10);
//		cout << dateVvod;
//		cout.precision(2);
//		cout << fixed;
//		cout.width(12);
//		cout << balPrice;
//		cout.width(9);
//		if (sumAmort != 0)
//		{
//			cout << sumAmort;
//		}
//		else cout << "        ";
//		cout.width(12);
//		cout << nakop;
//		cout.width(12);
//		if ((balPrice - nakop) > 0)
//		{
//			cout << balPrice - nakop << endl;
//		}
//		else cout << "      "<<endl;
//	}
//
//	double getBalPr() { return balPrice; }
//	double getAmort() { return sumAmort; }
//	double getNakop() { return nakop; }
//	
//};
//
//class typeImusch
//{
//private:
//	int nomIm;
//	string Nazv;
//	int Nmax;
//	int n;
//	imusch** MiIm;
//public:
//
//	typeImusch() { nomIm = 0; Nazv = "NoNazv"; Nmax = 70; n = 0; MiIm = new imusch * [Nmax]; };
//	typeImusch(string p) 
//	{
//		if (p.length() > 10)
//		{
//			nomIm = atoi(p.substr(5, 3).c_str());
//			Nazv = p.substr(8, 50);
//		}
//		else
//		{
//			Nazv = "NoFIO";
//		}
//		Nmax = 70;
//			n = 0;
//		MiIm = new imusch * [Nmax]; 
//	};
//	~typeImusch() { delete[]MiIm; };
//
//	typeImusch(typeImusch& o)
//	{
//		Nazv = o.Nazv;
//		Nmax = o.Nmax;
//		n = o.n;
//		MiIm = new imusch * [Nmax];
//		if (n > 0)
//			for (int i = 0; i < n; i++)
//			{
//				MiIm[i] = new imusch(*o.MiIm[i]);
//			}
//	}
//	void print()
//	{
//		cout.fill(' - ');
//		cout << "\n" << "<-----" << nomIm << "  " << Nazv << "  (" << n << "/" << Nmax << ") Edinits imuschestva" << "------------->" << endl;
//		if (n > 0)
//		{
//			for (int i = 0; i < n; i++)
//			{
//				MiIm[i]->print();
//			}
//		}
//	}
//
//	void add_imusch(string p)
//	{
//		if (n < Nmax)
//		{
//			MiIm[n] = new imusch(p);
//			n++;
//		}
//	}
//
//	double summa(int flag)
//	{
//		double vz = 0;
//		if (flag == 1)
//		{
//			for (int i = 0; i < n; i++)
//			{
//				vz += MiIm[i]->getBalPr();
//			}
//		}
//		else
//			if (flag == 2)
//			{
//				for (int i = 0; i < n; i++)
//				{
//					vz += MiIm[i]->getAmort();
//				}
//			}
//			else
//				if (flag == 3)
//					for (int i = 0; i < n; i++)
//					{
//						vz += MiIm[i]->getNakop();
//					}
//
//		return vz;
//	}
//
//};
//
//class litso
//{
//private:
//	int TabNom;
//	string FIO;
//	int Nmax;   //максимальное кол-во видов имущества
//	int n;
//	typeImusch** Mi;
//
//
//public:
//	litso() { TabNom = 0;  FIO = "NoFIO"; Nmax = 35; n = 0; Mi = new typeImusch * [Nmax]; };
//	litso(string p) 
//	{ 
//		if (p.length() > 10)
//		{
//			TabNom = atoi(p.substr(4, 3).c_str());
//			FIO = p.substr(7, 30);
//		}
//		else
//		{
//			TabNom = 0;
//			FIO = "NoFIO"; 
//		}
//		n = 0;
//		Nmax = 35;
//		Mi = new typeImusch * [Nmax]; 
//	};
//
//	~litso() { delete[]Mi; };
//
//	litso(litso& o)
//	{
//		FIO = o.FIO;
//		Nmax = o.Nmax;
//		n = o.n;
//		Mi = new typeImusch * [Nmax];
//		if (n > 0)
//			for (int i = 0; i < n; i++)
//			{
//				Mi[i] = new typeImusch(*o.Mi[i]); //доб. мет. getobj
//			}
//	}
//	void print()
//	{
//		cout << "\n\n" << "******************************************************************************************";
//		cout<<endl << TabNom << "  " << FIO << "  (" << n << "/" << Nmax << ") Vidov imuschestva" << endl;
//		double sum1 = 0, sum2 = 0, sum3=0;
//		if (n > 0)
//		{
//			for (int i = 0; i < n; i++)
//			{
//				Mi[i]->print();
//			sum1 += Mi[i]->summa(1);
//			sum2 += Mi[i]->summa(2);
//			sum3 += Mi[i]->summa(3);
//			}
//			
//		}
//		cout << "\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n> Summarno po litsu " << FIO << "Poluchim:\n>Balansovaya stoimost=" << sum1 <<"\n>Summa amortizatsii = " << sum2 << "\n>Nakoplenniy iznos = " << sum3 <<"\n>Ostatochnaya stoimost = " <<sum1-sum3<< endl;
//	}
//
//	void add_type(string p)
//	{
//			if (n<Nmax)
//			{
//				Mi[n] = new typeImusch(p);
//				n++;
//			}
//	}
//
//	void add_imusch(string p)
//	{
//		if (n < Nmax)
//		{
//			Mi[n-1]->add_imusch(p);
//		}
//	}
//};
//
//
//class dok
//{
//private:
//	string N_per;
//	string per;
//	int Nmax;
//	int n;   
//	litso** Ml;
//
//public:
//
//	dok()
//	{
//		N_per = "Net perioda";
//		per = "      ";
//		Nmax = 20;
//		n = 0;  //тек кол-во склвдов
//		Ml = new litso * [Nmax];
//	}
//
//	dok(const dok& o)
//	{
//		N_per = o.N_per;
//		per = o.per;
//		Nmax = o.Nmax;
//		n = o.n;
//		Ml = new litso * [Nmax];
//		if(n>0)
//			for (int i = 0; i < n; i++)
//			{
//				Ml[i] = new litso(*o.Ml[i]); //доб. мет. getobj
//			}
//	}
//
//	dok(string f_name)
//	{
//		ifstream f(f_name);
//		string a;
//		Nmax = 20;
//		Ml = new litso * [Nmax];
//		if(f.is_open())
//		{ 
//			int fl=0, fl_litso=0, fl_type=0, i=0, pos, pos1;
//			string p, z;
//			while (!f.eof())
//			{
//				getline(f, p);
//				i++;
//				pos = p.find(".N ");
//				if (pos>=0)
//				{
//					if (fl == 0)
//					{
//						getline(f, p);
//						getline(f, p);
//						N_per = p.substr(53, 12);
//						fl = 1;
//					}
//					pos = p.find(". ");
//
//				}
//				else
//				{
//					pos1 = p.find("->");
//					if (pos1 > 5)
//					{
//						fl_litso = 0;
//					}
//					else
//					{
//						if (p.length() > 10)
//						{
//							z = p.substr(0, 5).c_str();
//							if (fl_litso == 0)
//							{
//								if ((z == "     "))
//								{
//									Ml[n] = new litso(p); 
//									n++;
//									fl_litso = 1;
//								}
//							}
//							else
//							{
//								if ((z == "     ") && (o_digit(p[6]) == true))   
//								{
//									Ml[n - 1]->add_type(p);
//									fl_type = 1;
//								}
//								else
//									if ((o_digit(p[5]) == true) && (o_digit(p[12]) == true))
//									{
//										Ml[n - 1]->add_imusch(p);
//										fl_type = 1;
//									}
//							}
//						}
//					}
//				}
//
//			}
//		}
//		else
//		{
//			N_per = "Net perioda";
//			per = "      ";
//			
//			n = 0;  
//			Ml = new litso * [Nmax];
//		}
//	}
//
//	~dok()
//	{
//		if (n > 0)
//			for (int i = 0; i < n; i++)
//				delete Ml[i];
//		delete[]Ml;
//	}
//
//	void print()
//	{
//		
//
//		cout << "\n" <<"\t\t " << N_per << "  " << per << "  (" << n << "/" << Nmax << ") Otvetstvennih lits" << endl;
//		cout << "------------------------------------------------------------------------------------------------------------------------- " << endl;
//		cout << "|Nomer  |Inven|                                             | Debet| Data  |Balansovaya|  Summa  |Nakoplenniy|Ostatochn |" << endl;
//		cout << "|inv.   |tarn.|                  NAIMENOVANIE               |zatrat| vvoda |stoimost   |  amort  |   iznos   |stoim na  |" << endl;
//		cout << "|kart.  |nomer|                                             |      |v expl |           | za mes  |           | kon per  |" << endl;
//		cout << "|-----------------------------------------------------------------------------------------------------------------------|" << endl;
//		if (n > 0)
//		{
//			for (int i = 0; i < n; i++)
//			{
//				Ml[i]->print();  
//			}
//		}
//	}
//};
//
//int main()
//{
//	setlocale(LC_ALL, "866");
//	dok a("D:/2 курс 4 семестр/ООП_2_семестр/Лабы/var05_2.TXT");
//	a.print();
//	
//	system("pause");
//} //моя лаба (3 в другом проекте)



//Закотнюк:
 
 
//#include <iostream>
//#include <math.h>
//#include <conio.h>
//#include <string>
//#include <fstream>
//#include <iomanip>
//#include <locale>
//#include <windows.h>
//
//using namespace std;
//
//class oborotPoDebetu
//{
//private:
//	string schet;
//	double summa;
//public:
//	oborotPoDebetu()
//	{
//		schet = "--";
//		summa = 0;
//	};
//	oborotPoDebetu(string p)
//	{
//		if (p.length() > 53)
//		{
//			schet = p.substr(33, 7);
//			summa = atof(p.substr(40, 14).c_str());
//		}
//	};
//	~oborotPoDebetu() {};
//
//	oborotPoDebetu(oborotPoDebetu& o)
//	{
//		schet = o.schet;
//		summa = o.summa;
//	}
//	void print()
//	{
//
//		
//		cout << fixed;
//		cout.precision(1);
//		cout.width(13);
//		cout << schet;
//
//		if (summa != 0)
//		{
//			cout << fixed;
//			cout.precision(2);
//			cout.width(13);
//			cout << summa;
//		}
//		else cout << "      -      ";
//		
//	}
//	
//	string getSchet() { return schet; }
//	double getSumma() { return summa; }
//
//	string get_TN()
//	{
//		return schet;
//	}
//
//	void modify(double p1)
//	{
//		summa += p1;
//	}
//};
//
//class mainSchet
//{
//private:
//	string nomSchet;
//	double debet;            
//	double credit;            
//	int Nmax;
//	int n;
//	oborotPoDebetu** MiPer;
//	double oborotPoKreditu;
//	double itogDebet;
//	double itogCredit;
//public:
//
//	
//	mainSchet() 
//	{ 
//	nomSchet = "---"; debet = 0; credit = 0; 
//	Nmax = 180; n = 0; MiPer = new oborotPoDebetu * [Nmax]; 
//	oborotPoKreditu = 0;
//	itogDebet = 0;
//	itogCredit = 0;
//	};
//	mainSchet(string p)
//	{
//		Nmax = 180;
//		n = 0;
//		MiPer = new oborotPoDebetu * [Nmax];
//		if (p.length() > 104)
//		{
//			nomSchet = p.substr(0, 6);
//			debet = atof(p.substr(7, 13).c_str());
//			credit = atof(p.substr(21, 34).c_str());
//
//			double buf = atof(p.substr(33, 7).c_str());
//			if (buf > 0)
//			{
//				MiPer[n] = new oborotPoDebetu(p);
//				n++;
//			}
//			oborotPoKreditu = atof(p.substr(67, 13).c_str());
//			itogDebet = atof(p.substr(80, 12).c_str());
//			itogCredit = atof(p.substr(92, 13).c_str());
//		}
//		else
//		{
//			nomSchet = "---"; debet = 0; credit = 0;
//			Nmax = 70; n = 0; MiPer = new oborotPoDebetu * [Nmax];
//			oborotPoKreditu = 0;
//			itogDebet = 0;
//			itogCredit = 0;
//		}
//	};
//	~mainSchet() { 
//		if (n > 0)
//			for (int i = 0; i < n; i++)
//				delete MiPer[i];
//		delete[]MiPer; 
//	};
//
//	mainSchet(mainSchet& o)
//	{
//		nomSchet = o.nomSchet;
//		debet = o.debet;
//		credit = o.credit;
//		Nmax = o.Nmax;
//		n = o.n;
//		MiPer = new oborotPoDebetu * [Nmax];
//		if (n > 0)
//			for (int i = 0; i < n; i++)
//			{
//				MiPer[i] = new oborotPoDebetu(*o.MiPer[i]); //////////&&
//			}
//		oborotPoKreditu = o.oborotPoKreditu;
//		itogDebet = o.itogDebet;
//		itogCredit = o.itogCredit;
//	}
//
//	double sumDeb()
//	{
//		int i;
//		double vz = 0;
//		for (i = 0; i < n; i++)
//		{
//			vz += MiPer[i]->getSumma();
//		}
//		return vz;
//	}
//	void print()
//	{
//		cout << "\n" << nomSchet;
//		cout << "\t";
//		if (debet != 0)
//		{
//			cout << fixed;
//			cout.precision(2);
//			cout.width(13);
//			cout << debet;
//		}
//		else cout << "      -      ";
//		if (credit != 0)
//		{
//			cout.width(13);
//			cout << credit;
//		}
//		else cout << "      -      ";
//		if (n > 0)
//		{
//			MiPer[0]->print();
//		}
//		else cout << "                   -      ";
//
//		cout.width(13);
//		double sum = sumDeb();
//		if (sum != 0)
//		{
//			cout.width(13);
//			cout << sum;
//		}
//		else cout << "      -      ";
//		
//		if (oborotPoKreditu != 0)
//		{
//			cout.width(13);
//			cout << oborotPoKreditu;
//		}
//		else cout << "      -      ";
//
//		if (itogDebet != 0)
//		{
//			cout.width(13);
//			cout << itogDebet;
//		}
//		else cout << "      -      ";
//
//		if (itogCredit != 0)
//		{
//			cout.width(13);
//			cout << itogCredit;
//		}
//		else cout << "      -      ";
//
//		if (n > 1)
//		{
//			for (int i = 1; i < n; i++)
//			{
//				cout << endl<<"\t\t\t\t  ";
//				MiPer[i]->print();
//			}
//		}
//	}
//
//	void add_perevod(string p)
//	{
//		if (n < Nmax)
//		{
//			MiPer[n] = new oborotPoDebetu(p);
//			n++;
//		}
//	}
//	
//	int getN() { return n; }
//
//	double getDeb() { return debet; }
//	double getCred() { return credit; }
//	double getOborot() { return oborotPoKreditu; }
//	double getItDeb() { return itogDebet; }
//	double getItCred() { return itogCredit; }
//
//	string get_TN()
//	{
//		return nomSchet;
//	}
//
//	double get_data(int p1)
//	{
//		return MiPer[p1]->getSumma();
//	}
//
//	string get_TN(int p1)
//	{
//		return MiPer[p1]->get_TN();
//	}
//
//
//	int find_ind_per(string par)
//	{
//		for (int i = 0; i < n; i++)
//		{
//			if (MiPer[i]->get_TN() == par)
//				return i;
//		}
//		return -1;
//	}
//
//	void modify(double p1, double p2, double p3)
//	{
//		debet = itogDebet;
//		credit = itogCredit;
//		oborotPoKreditu = p1;
//		itogDebet = p2;
//		itogCredit = p3;
//	}
//
//	void modify_data(int p1, double p2)
//	{
//		if(p1<n)
//		MiPer[p1]->modify(p2);
//	}
//
//	oborotPoDebetu* get_per(int p1)
//	{
//		return MiPer[p1];
//	}
//
//	void add_per(oborotPoDebetu p1)
//	{
//		MiPer[n] = new oborotPoDebetu(p1);
//		n++;
//	}
//
//};
//
//class dok
//{
//private:
//	string N_per;
//	int Nmax;
//	int n;
//	mainSchet** Msch;
//
//public:
//
//	dok()
//	{
//		N_per = "Net perioda";
//		Nmax = 180;
//		n = 0;
//		Msch = new mainSchet * [Nmax];
//	}
//
//	double fulSum(int flag)
//	{
//		double vz = 0;
//		int i;
//		for (i = 0; i < n; i++)
//		{
//			if (flag == 0)
//			{
//				vz += Msch[i]->getDeb();
//			}
//			if (flag == 1)
//			{
//				vz += Msch[i]->getCred();
//			}
//			if (flag == 2)
//			{
//				vz += Msch[i]->sumDeb();
//			}
//			if (flag == 3)
//			{
//				vz += Msch[i]->getOborot();
//			}
//			if (flag == 4)
//			{
//				vz += Msch[i]->getItDeb();
//			}
//			if (flag == 5)
//			{
//				vz += Msch[i]->getItCred();
//			}
//		}
//		return vz;
//	}
//
//	dok(const dok& o)
//	{
//		N_per = o.N_per;
//		Nmax = o.Nmax;
//		n = o.n;
//		Msch = new mainSchet * [Nmax];
//		if (n > 0)
//			for (int i = 0; i < n; i++)
//			{
//				Msch[i] = new mainSchet(*o.Msch[i]);
//			}
//	}
//
//	dok(string f_name)
//	{
//		ifstream f(f_name);
//		string a;
//		Nmax = 180;
//		n = 0;
//		Msch = new mainSchet * [Nmax];
//		if (f.is_open())
//		{
//			int i = 0, pos, pos1;
//			string p, z;
//			getline(f, p);
//			getline(f, p);
//			getline(f, p);
//			pos = p.find(" §  ");
//			pos1 = p.find(" Ј.");
//			N_per = p.substr(pos+3, pos1-pos-3);
//
//			while (!f.eof())
//			{
//				getline(f, p);
//				pos = p.find(".");
//				pos1 = p.find(":");
//				if (pos > 2)
//				{
//					if ((pos > 2) && (pos < 10))
//					{
//						Msch[n] = new mainSchet(p);
//						n++;
//					}
//					else
//						if((pos>10)&&(pos1<10))
//						{
//							Msch[n-1]->add_perevod(p);
//						}
//				}
//			}
//		}
//		else
//		{
//			N_per = "Net perioda";
//			n = 0;
//			Msch = new mainSchet * [Nmax];
//		}
//	}
//
//	~dok()
//	{
//		if (n > 0)
//			for (int i = 0; i < n; i++)
//				delete Msch[i];
//		delete[]Msch;
//	}
//
//	void add(mainSchet p)
//	{
//		Msch[n] = new mainSchet(p);
//		n++;
//	}
//
//	void print()
//	{
//
//
//		cout << "\n" << "\t\t " << N_per << "  " << "  (" << n << "/" << Nmax << ") Schetov" << endl;
//		cout << "------------------------------------------------------------------------------------------------------------------- " << endl;
//		cout << "|       |            |            |            |            |            |             |            |             |" << endl;
//		cout << "|       |            |            |            |            |            |             |            |             |" << endl;
//		cout << "|       |            |            |            |            |            |             |            |             |" << endl;
//		cout << "|-----------------------------------------------------------------------------------------------------------------|" << endl;
//		if (n > 0)
//		{
//			for (int i = 0; i < n; i++)
//			{
//				Msch[i]->print();
//				cout << endl;
//			}
//		}
//		cout.width(6);
//		cout << "Summary:";
//		cout.width(13); 
//		cout << fulSum(0)<<"|";
//		cout.width(13); 
//		cout << fulSum(1) << "|";
//		cout.width(24); cout << " ";
//		cout.width(13); 
//		cout << fulSum(2) << "|";
//		cout.width(13); 
//		cout << fulSum(3) << "|";
//		cout << fulSum(4) << "|";
//		cout.width(13); 
//		cout << fulSum(5) << "|" << endl;
//	}
//
//	int find_ind(string par)
//	{
//		for (int i = 0; i < n; i++)
//		{
//			if (Msch[i]->get_TN() == par)
//				return i;
//		}
//		return -1;
//	}
//
//	dok operator=(dok o)
//	{
//		if (this != &o)
//		{
//			if (n > 0)
//				for (int i = 0; i < n; i++)
//					delete Msch[i];
//			delete[]Msch;
//		
//			N_per = o.N_per;
//			Nmax = o.Nmax;
//			n = o.n;
//			Msch = new mainSchet * [Nmax];
//			if (n > 0)
//				for (int i = 0; i < n; i++)
//				{
//					Msch[i] = new mainSchet(*o.Msch[i]);
//				}
//		}
//		return *this;
//	}
//		
//	dok operator+(dok o)
//	{
//		dok tmp(*this);
//		int i, j, indSch, indPerevod;
//		double buf;
//		tmp.N_per += ", ";
//		tmp.N_per += o.N_per;
//		string TN = "";
//		string TN2 = "";
//		for (i = 0; i < o.n; i++)
//		{
//			TN = o.Msch[i]->get_TN();
//			indSch = find_ind(TN);
//			if (indSch >= 0)
//			{
//				tmp.Msch[indSch]->modify(o.Msch[i]->getOborot(), o.Msch[i]->getItDeb(), o.Msch[i]->getItCred());
//				if (o.Msch[indSch]->getN() > 0)
//				{
//					for (j = 0; j < o.Msch[i]->getN(); j++)
//					{
//						TN2 = o.Msch[i]->get_TN(j);
//						buf = o.Msch[i]->get_data(j);
//						indPerevod = Msch[indSch]->find_ind_per(TN2);
//						if (indPerevod >= 0)
//						{
//							tmp.Msch[indSch]->modify_data(indPerevod, buf);
//						}
//						else
//						{
//							tmp.Msch[indSch]->add_per(*o.Msch[i]->get_per(j));
//						}
//					}
//				}
//			}
//			else
//			{
//				tmp.add(*o.Msch[i]);
//			}
//		}
//		return tmp;
//	}
//
//
//};
//
//int main()
//{
//	setlocale(LC_ALL, "866");
//	dok a("var07_1.TXT");
//	dok b("var07_2.TXT");
//	//a.print();
//	//b.print();
//	dok c = a + b;
//	c.print();
//	system("pause");
//}

//Зотова 3 лаба вариант 8

//#include <iostream>
//#include <math.h>
//#include <conio.h>
//#include <string>
//#include <fstream>
//#include <iomanip>
//#include <locale>
//#include <windows.h>
//
//using namespace std;
//
//bool o_digit(char p)
//{
//	bool vz = false;
//	if (p > 47 && p < 58)
//	{
//		vz = true;
//	}
//	return vz;
//}
//
//class Info
//{
//private:
//	int tabNom;
//	string FIO;
//	string gr;
//	int sp;
//	string time1;
//	int goout;
//	string time2;
//	string time3;
//public:
//	Info()
//	{
//		tabNom = 0;
//		FIO = "No FIO";
//		gr = "0";
//		sp = 0;
//		time1 = "00:00";
//		goout = 0;
//		time2 = "00:00";
//		time3 = "00:00";
//	};
//	Info(string p)
//	{
//		if (p.length() > 55)
//		{
//			tabNom = atoi(p.substr(1, 7).c_str());
//			FIO = p.substr(8, 15);
//			gr = p.substr(25,1);
//			sp = atoi(p.substr(29, 1).c_str());
//			time1 = p.substr(32, 5);
//			goout = atoi(p.substr(39, 1).c_str());
//			time2 = p.substr(42, 5);
//			time3 = p.substr(52, 5);
//		}
//	};
//	~Info() {};
//
//	Info(Info& o)
//	{
//		tabNom = o.tabNom;
//		FIO = o.FIO;
//		gr = o.gr;
//		sp = o.sp;
//		time1 = o.time1;
//		goout = o.goout;
//		time2 = o.time2;
//		time3 = o.time3;
//	}
//	void vivod()
//	{
//		cout << fixed;
//		cout.precision(1);
//		cout.width(10);
//		cout << tabNom;
//
//		cout.width(13);
//		cout << FIO;
//
//		cout << fixed;
//		cout.precision(1);
//		cout.width(3);
//		cout << gr;
//
//		if (sp >= 1)
//		{
//			cout.width(3);
//			cout << sp;
//		}
//		else
//		{
//			cout.width(3);
//			cout << "";
//		}
//
//		cout << fixed;
//		cout.precision(1);
//		cout.width(8);
//		cout << time1;
//
//		cout << fixed;
//		cout.precision(1);
//		cout.width(3);
//		cout << goout;
//
//		cout << fixed;
//		cout.precision(1);
//		cout.width(8);
//		cout << time2;
//
//		cout << fixed;
//		cout.precision(1);
//		cout.width(8);
//		cout << time3;
//	}
//	int getGr() 
//	{
//		if (o_digit(gr[0]) == true)
//			return atoi(gr.c_str());
//		else return 0;
//	}
//
//	int getSp() { return sp; }
//	int getGoOut() { return goout; }
//
//};
//
//class Smena
//{
//private:
//	int nomSm;
//	int n;
//	int Nmax;
//	Info** MasInfo;
//public:
//	Smena()
//	{
//		nomSm = -1;
//		Nmax = 50;
//		n = 0;
//		MasInfo = new Info * [Nmax];
//	};
//	Smena(string p)
//	{
//		int pos = 0;
//		Nmax = 50;
//		n = 0;
//		MasInfo = new Info * [Nmax];
//		if (p.length() > 1)
//		{
//			nomSm = atoi(p.substr(0, 2).c_str());
//		}
//		else
//		{
//			nomSm = -1;
//		}
//	};
//	~Smena() { delete[]MasInfo; };
//
//	Smena(Smena& o)
//	{
//		nomSm = o.nomSm;
//		Nmax = o.Nmax;
//		n = o.n;
//		MasInfo = new Info * [Nmax];
//		if (n > 0)
//			for (int i = 0; i < n; i++)
//			{
//				MasInfo[i] = new Info(*o.MasInfo[i]); 
//			}
//	}
//	
//	void vivod()
//	{
//		//cout << "\n  Smena: " << nomSm << endl;
//		cout <<endl<< " Smena: " << nomSm << endl;
//		int i;
//		for (i = 0; i < n; i++)
//		{
//			if ((i % 2 == 0)&&(i!=0))cout << endl;
//			MasInfo[i]->vivod();
//			cout << "  ";
//
//		}
//	}
//
//	void add_Info(string p)
//	{
//		if (n < Nmax)
//		{
//			MasInfo[n] = new Info(p);
//			n++;
//		}
//	}
//	int getN() { return n; }
//	int getGrSum() 
//	{
//		int i, vz=0;
//		for (i = 0; i < n; i++)
//		{
//			if(MasInfo[i]->getGr() == nomSm)////////////// ==смена
//			vz++;
//		}
//		return vz;
//	}
//	int getSpSum()
//	{
//		int i, vz = 0;
//		for (i = 0; i < n; i++)
//		{
//			if(MasInfo[i]->getSp()==nomSm)
//			vz++;
//		}
//		return vz;
//	}
//
//	int getGoOutSum()
//	{
//		int i, vz = 0;
//		for (i = 0; i < n; i++)
//		{
//			if(MasInfo[i]->getGoOut() == nomSm)
//			vz++;
//		}
//		return vz;
//	}
//
//	int getSmena()
//	{
//		return nomSm;
//	}
//};
//
//class Uchastok
//{
//private:
//	string date;
//	string uchname;
//	int n;
//	int Nmax;
//	Smena** MasSm;
//public:
//	Uchastok()
//	{
//		date = "No date";
//		Nmax = 3;
//		n = 0;
//		MasSm = new Smena * [Nmax];
//		uchname = "---";
//	};
//	Uchastok(string p)
//	{
//		int pos = 0, pos1 = 0;
//		Nmax = 3;
//		n = 0;
//		MasSm = new Smena * [Nmax];
//		if (p.length() > 5)
//		{
//			pos = p.find("->");
//			date = p.substr(pos + 2, 12);
//			pos = p.find(".");
//			p = p.substr(pos + 2, 50);
//			pos = p.find("->");
//			pos1 = p.find(".");
//			uchname = p.substr(pos + 2, pos1-pos);
//		}
//		else
//		{
//			date = "No date";
//			uchname = "---";
//		}
//	};
//	~Uchastok() { delete[]MasSm; };
//
//	Uchastok(Uchastok& o)
//	{
//		date = o.date;
//		Nmax = o.Nmax;
//		n = o.n;
//		MasSm = new Smena * [Nmax];
//		uchname = o.uchname;
//		if (n > 0)
//			for (int i = 0; i < n; i++)
//			{
//				MasSm[i] = new Smena(*o.MasSm[i]);
//			}
//	}
//
//	void vivod()
//	{
//		int i;
//		cout << "   Date: " << date << "   Uchastok:" << uchname;
//		cout << endl;
//		cout << "    |------------------------------------------------------|    |------------------------------------------------------| " << endl;
//		cout << "    | Tab.|               |  |  |      |   |      |  |     |    | Tab.|               |  |  |      |   |      |  |     |" << endl;
//		cout << "    | nom.|  Surname      |Gr|Sp| Time |V  | Time |Pr| Time|    | nom.|  Surname      |Gr|Sp| Time |V  | Time |Pr| Time|" << endl;
//		cout << "    |     |               |  |  |      |   |      |  |     |    |     |               |  |  |      |   |      |  |     |" << endl;
//		cout << "    |------------------------------------------------------|    |------------------------------------------------------|" << endl;
//		int a = 0, b = 0, c = 0, d = 0;
//		for (i = 0; i < n; i++)
//		{
//			MasSm[i]->vivod();
//			cout << "\nItogo:(Smena "<< MasSm[i]->getSmena()<<")"<< MasSm[i]->getN();
//			cout << "; po grafiku: " << MasSm[i]->getGrSum();
//			cout << "; spusk: " << MasSm[i]->getSpSum();
//			cout << "; viezd: " << MasSm[i]->getGoOutSum()<<endl;
//			a += MasSm[i]->getN();
//			b += MasSm[i]->getGrSum();
//			c += MasSm[i]->getSpSum();
//			d += MasSm[i]->getGoOutSum();
//		}
//		cout << "\n------------------------------------------------------------------";
//		cout << "\nItogo:(po uchastku)" << a;
//		cout << "; po grafiku: " << b;
//		cout << "; spusk: " << c;
//		cout << "; viezd: " << d;
//	}
//
//	void add_smena(string p)
//	{
//		if (n < Nmax)
//		{
//			MasSm[n] = new Smena(p);
//			n++;
//		}
//	}
//
//	void add_Info_1(string p)
//	{
//		if (n < Nmax)
//		{
//			MasSm[n-1] ->add_Info(p);
//			//n++;
//		}
//	}
//	int getN() { return n; }
//	string get_Nazv()	{	return uchname;	}
//
//	Smena* get_smena(int ind)
//	{
//		return MasSm[ind];
//	}
//
//	void add_smena_obj(Smena sm)
//	{
//		MasSm[n] = new Smena(sm);
//		n++;
//	}
//
//	int getGrSum()
//	{
//		int i, vz = 0;
//		for (i = 0; i < n; i++)
//		{
//			vz += MasSm[i]->getGrSum();
//		}
//		return vz;
//	}
//	int getSpSum()
//	{
//		int i, vz = 0;
//		for (i = 0; i < n; i++)
//		{
//				vz+= MasSm[i]->getSpSum();
//		}
//		return vz;
//	}
//
//	int getGoOutSum()
//	{
//		int i, vz = 0;
//		for (i = 0; i < n; i++)
//		{
//				vz+= MasSm[i]->getGoOutSum();
//		}
//		return vz;
//	}
//	int getN_viezdov()
//	{
//		int i, vz=0;
//		for ( i = 0; i < n; i++)
//		{
//			vz += MasSm[i]->getN();
//		}
//		return vz;
//	}
//};
//
//class dok
//{
//private:
//	int Nmax;
//	int n;
//	Uchastok** MasUch;
//
//public:
//
//	dok()
//	{
//		Nmax = 20;
//		n = 0;
//		MasUch = new Uchastok * [Nmax];
//	}
//
//	dok(const dok& o)
//	{
//		Nmax = o.Nmax;
//		n = o.n;
//		MasUch = new Uchastok * [Nmax];
//		if (n > 0)
//			for (int i = 0; i < n; i++)
//			{
//				MasUch[i] = new Uchastok(*o.MasUch[i]);
//			}
//	}
//
//	dok(string f_name)
//	{
//		ifstream f(f_name);
//		string a;
//		Nmax = 20;
//		n = 0;
//		int sch=0;
//		MasUch = new Uchastok * [Nmax];
//		if (f.is_open())
//		{
//			int i = 0, pos, pos1;
//			string p, t;
//
//			while (!f.eof())
//			{
//				getline(f, p);
//				if (p.length() > 30)
//				{
//					pos = p.find("->");
//					if (pos > 2)
//					{
//						MasUch[n] = new Uchastok(p);
//						pos = p.find(":");
//						p = p.substr(pos + 1, 2);
//						MasUch[n]->add_smena(p);
//						n++;
//					}
//					else
//					if (o_digit(p[7])==true)
//					{
//						t = p.substr(0, 57);
//						MasUch[n - 1]->add_Info_1(t);
//						if (p.length() > 60)
//						{
//							p = p.substr(60, 115);
//							MasUch[n - 1]->add_Info_1(p);
//						}
//					}
//				}
//			}
//		}
//	}
//
//	~dok()
//	{
//		if (n > 0)
//			for (int i = 0; i < n; i++)
//				delete MasUch[i];
//		delete[]MasUch;
//	}
//
//	void vivod()
//	{if (n > 0)
//		{
//		int a = 0, b = 0, c = 0, d = 0, e=0;
//			for (int i = 0; i < n; i++)
//			{
//				MasUch[i]->vivod();
//
//				a+= MasUch[i]->getN();
//				b+= MasUch[i]->getGrSum();
//				c+= MasUch[i]->getSpSum();
//				d+= MasUch[i]->getGoOutSum();
//				e+= MasUch[i]->getN_viezdov();
//
//				cout << endl << endl;
//			}
//			cout << "\n------------------------------------------------------------------";
//			cout <<endl<< "\nItogo:(po vsem uchastkam) - " << a << " (smen)  ;";
//			cout << endl << " viezdov:" << e;
//			cout << endl << " po grafiku: " << b;
//			cout << endl << " spusk: " << c;
//			cout << endl << " viezd: " << d;
//		}
//	}
//
//	int find_ind(string nazv)
//	{
//		int i, vz = -1;
//		for (i = 0; i < n; i++)
//		{
//			if (MasUch[i]->get_Nazv() == nazv)
//				vz = i;
//		}
//		return vz;
//	}
//
//	dok operator=(dok o)
//	{
//		if (this != &o)
//		{
//			if (n > 0)
//				for (int i = 0; i < n; i++)
//					delete MasUch[i];
//			delete[]MasUch;
//
//			Nmax = o.Nmax;
//			n = o.n;
//			MasUch = new Uchastok * [Nmax];
//			if (n > 0)
//				for (int i = 0; i < n; i++)
//				{
//					MasUch[i] = new Uchastok(*o.MasUch[i]);
//				}
//		}
//		return *this;
//	}
//
//	dok operator+(dok o)
//	{
//		dok tmp(*this);
//		int i, j, k, ind_uch;
//		string nazvuUch="";
//		for (i = 0; i < o.n; i++)
//		{
//			nazvuUch = o.MasUch[i]->get_Nazv();
//			ind_uch = find_ind(nazvuUch);
//			if (ind_uch >= 0)
//			{
//				for (j = 0; j < MasUch[ind_uch]->getN(); j++)
//				{
//					Smena buf(*o.MasUch[i]->get_smena(j));
//					tmp.MasUch[ind_uch]->add_smena_obj(buf);
//				}
//			}
//		}
//		return tmp;
//	}
//};
//
//int main()
//{
//	setlocale(LC_ALL, "866");
//	dok a("C:/Users/User/OneDrive/Desktop/var08_1.TXT");
//	dok b("C:/Users/User/OneDrive/Desktop/var08_2.TXT");
//	//a.vivod();
//	//b.vivod();
//	dok c = a+b;
//	c.vivod();
//	system("pause");
//}



//Татьяничев 2/3

//#define _CRT_SECURE_NO_WARNINGS
//#include <windows.h> 
//#include <stdio.h>
//#include <locale.h>
//#include <conio.h>
//#include<stdlib.h>
//#include<string.h>
//#include <iostream>
//#include <math.h>
//#include <string>
//#include <fstream>
//#include <iomanip>
//#include "Menu.h"
//
//
//
//using namespace std;
//
//bool o_digit(char p)
//{
//	bool vz = false;
//	if (p > 47 && p < 58)
//	{vz = true;}
//	return vz;
//}
//
//class Person
//{
//private:
//	int tabNom;
//	string FIO;
//	int nomBL;
//	int typeNetr;
//	string dateBeg;
//	string dateEnd;
//	int percent;
//	double sumDnevPos;
//	int nDays1;
//	double SumPos;
//	int nDays2;
//	double summaZaSchPredpr;
//	int nDays3;
//	double summaSotzStrah;
//
//public:
//	Person()
//	{
//		tabNom = 0;
//		FIO = "noFio";
//		nomBL = 0;
//		typeNetr = 0;
//		dateBeg = "No date";
//		dateEnd = "No date";
//		percent = 0;
//		sumDnevPos = 0;
//		nDays1 = 0;
//		SumPos = 0;
//		nDays2 = 0;
//		summaZaSchPredpr = 0;
//		nDays3 = 0;
//		summaSotzStrah = 0;
//	};
//	Person(string p)
//	{
//		if (p.length() > 53)
//		{
//			int pos;
//			tabNom = atoi(p.substr(3, 4).c_str());
//			pos = p.find(".");
//			FIO = p.substr(7, pos+2-7);
//			nomBL = atoi(p.substr(28, 6).c_str());
//			typeNetr = atoi(p.substr(35, 4).c_str());
//
//			dateBeg = p.substr(40, 8);
//			dateEnd = p.substr(49, 8);
//			percent = atoi(p.substr(58, 3).c_str());
//			sumDnevPos = atof(p.substr(62, 10).c_str());
//			nDays1 = atoi(p.substr(72, 6).c_str());
//			SumPos = atof(p.substr(78, 11).c_str());
//			nDays2 = atoi(p.substr(89, 4).c_str());
//			summaZaSchPredpr = atof(p.substr(93, 11).c_str());
//			nDays3 = atoi(p.substr(104, 4).c_str());
//			summaSotzStrah = atof(p.substr(108, 11).c_str());
//		}
//	};
//	~Person() {};
//
//	Person(Person& o)
//	{
//		tabNom = o.tabNom;
//		FIO = o.FIO;
//		nomBL = o.nomBL;
//		typeNetr = o.typeNetr;
//		dateBeg = o.dateBeg;
//		dateEnd = o.dateEnd;
//		percent = o.percent;
//		sumDnevPos = o.sumDnevPos;
//		nDays1 = o.nDays1;
//		SumPos = o.SumPos;
//		nDays2 = o.nDays2;
//		summaZaSchPredpr = o.summaZaSchPredpr;
//		nDays3 = o.nDays3;
//		summaSotzStrah = o.summaSotzStrah;
//	}
//	void print()
//	{
//		cout << endl;
//		cout << setw(7) << tabNom;
//		cout << setw(20) << FIO;
//		cout << setw(6) << nomBL;
//		cout << setw(4) << typeNetr;
//		cout << setw(10) << dateBeg;
//		cout << setw(10) << dateEnd;
//		cout << setw(5) << percent;
//		cout << fixed << setprecision(2) << setw(12) << sumDnevPos;
//		cout << setw(5) << nDays1;
//		cout << fixed << setprecision(2) << setw(12) << SumPos;
//
//		cout<< setw(5) << nDays2;
//		cout << fixed << setprecision(2) << setw(12) << summaZaSchPredpr;
//
//		cout << setw(5) << nDays3;
//		cout << fixed << setprecision(2) << setw(12) << summaSotzStrah;
//		
//	}
//
//	double get_sum(int fl)
//	{
//		double vz = -1;
//		if (fl == 1)
//			vz = nDays1;
//		if (fl == 2)
//			vz = SumPos;
//		if (fl == 3)
//			vz = nDays2;
//		if (fl == 4)
//			vz = summaZaSchPredpr;
//		if (fl == 5)
//			vz = nDays3;
//		if (fl == 6)
//			vz = summaSotzStrah;
//			return vz;
//	}
//	string get_mes_god()
//	{
//		return dateBeg.substr(3,5);
//	}
//
//	int getTabNom()
//	{
//		return tabNom;
//	}
//};
//
//class bolezn
//{
//private:
//	int CodeBolezn;
//	int Nmax;
//	int n;
//	Person** MasPersons;
//public:
//	bolezn()
//	{
//		CodeBolezn = -1;
//		Nmax = 20; n = 0;
//		MasPersons = new Person * [Nmax];
//	};
//
//	bolezn(int code)
//	{
//		CodeBolezn = code;
//		Nmax = 40; n = 0;
//		MasPersons = new Person * [Nmax];
//	}
//
//	~bolezn() { delete[]MasPersons; };
//
//	bolezn(bolezn& o)
//	{
//		CodeBolezn = o.CodeBolezn;
//		Nmax = o.Nmax;
//		n = o.n;
//		MasPersons = new Person * [Nmax];
//		if (n > 0)
//			for (int i = 0; i < n; i++)
//			{
//				MasPersons[i] = new Person(*o.MasPersons[i]);
//			}
//	}
//
//	void add_new_pers(string p)
//	{
//		MasPersons[n] = new Person(p);
//		n++;
//	}
//
//	void print()
//	{
//		if (CodeBolezn != 0)
//			cout << endl << "Code bolezn = " << CodeBolezn << "(" << n << "/" << Nmax << ")";
//		for (int i = 0; i < n; i++)
//		{
//			MasPersons[i]->print(); //////////
//			cout << endl;
//		}
//		if (CodeBolezn != 0)
//		{
//			cout << "----------------------------------------------------------------------------------------------------------------------------------" << endl;
//			cout << "\t\t\t\t\t\tItogo po zabolevaniyu:" << endl;
//			cout << fixed << setprecision(0) << setw(79) << get_sum(1);
//			cout << fixed << setprecision(2) << setw(12) << get_sum(2);
//			cout << endl << "----------------------------------------------------------------------------------------------------------------------------------" << endl;
//		}
//	}
//
//	double get_sum(int fl)
//	{
//		int i;
//		double vz = 0;
//		for (i = 0; i < n; i++)
//		{
//			vz += MasPersons[i]->get_sum(fl);
//		}
//		return vz;
//	}
//
//	int getN() { return n; }
//
//	Person* getPerson(int ind)
//	{
//		return MasPersons[ind];
//
//	}
//
//	int get_ill_type()
//	{
//		return CodeBolezn;
//	}
//
//	void addPerson(Person p)
//	{
//		MasPersons[n] = new Person(p);
//		n++;
//	}
//
//	void sort() //сортировка по возрастанию табельных номеров
//	{
//		int i, buf1, buf2;
//		Person* buf;
//		if (n > 1)
//		{
//			for (i = 0; i < n - 1; i++)
//			{
//				buf1 = MasPersons[i]->getTabNom();
//				buf2 = MasPersons[i + 1]->getTabNom();
//				if (buf2 < buf1)
//				{
//					buf = MasPersons[i];
//					MasPersons[i] = MasPersons[i + 1];
//					MasPersons[i + 1] = buf;
//					i = 0;
//				}
//			}
//		}
//	}
//};
//
//typedef struct Sums
//{
//	double days1=0;
//	double sum1=0;
//	double days2=0;
//	double sum2=0;
//	double days3=0;
//	double sum3=0;
//} Sums;
//
//class Vedomost
//{
//private:
//	string travmOrill;
//	int Nmax;
//	int n;
//	bolezn** MasBols;
//public:
//	Vedomost()
//	{ 
//		travmOrill = "No type";
//		Nmax = 20; n = 0;
//		MasBols = new bolezn * [Nmax];
//	};
//	Vedomost(string p)
//	{
//		if (p.length() > 20)
//		{	Nmax = 20;
//			n = 0;
//			MasBols = new bolezn * [Nmax];
//			string t;
//			int pos, pos1;
//			pos = p.find(" ");
//			t = p.substr(pos + 2, 20);
//			pos1 = t.find(" ");
//			travmOrill = p.substr(0, pos + pos1+2);
//		}
//		else
//		{
//			Nmax = 20; n = 0;
//			MasBols = new bolezn * [Nmax];
//			travmOrill = "No type";
//		}
//	};
//	~Vedomost() { delete[]MasBols; };
//
//	Vedomost(Vedomost& o)
//	{
//		travmOrill = o.travmOrill;
//		Nmax = o.Nmax;
//		n = o.n;
//		MasBols = new bolezn * [Nmax];
//		if (n > 0)
//			for (int i = 0; i < n; i++)
//			{
//				MasBols[i] = new bolezn(*o.MasBols[i]);
//			}
//	}
//
//	int add_bolezn(int code)
//	{
//		if (n < Nmax)
//		{
//			MasBols[n] = new bolezn(code);
//			n++;
//		}
//		return n - 1;
//	}
//
//	void add_person(int ind, string p)
//	{
//		MasBols[ind]->add_new_pers(p);
//	}
//
//	void print()
//	{
//		cout <<"\t Vid:  " << travmOrill << "(" << n << "/" << Nmax << ")" << endl;
//		cout << " |----------------------------------------------------------------------------------------------------------------------------| " << endl;
//		cout << " | Tab. |                  | nom |vi | date    | date   |  % |   summa   |  d  |   Summa   |  d |   Summa   | d  |   Summa    |" << endl;
//		cout << " | nom. |  FIO             | bol |d  | nach    |  con   |poso|   dnev    |  a  |   poso    |  a |   Za sch  | a  |   Za schet |" << endl;
//		cout << " |      |                  |list |ne | bol     |  bol   |biya|   nogo    |  y  |   biya    |  y |   predpr  | y  |   sotcz    | " << endl;
//		cout << " |      |                  |list |tr | list    | list   |    |   posob   |  s  |           |  s |           | s  |   straha   |" << endl;
//		cout << " |----------------------------------------------------------------------------------------------------------------------------|" << endl;
//		
//		for (int i = 0; i < n; i++)
//		{
//			MasBols[i]->print();
//			cout << endl;
//		}
//	}
//
//	double get_sum(int fl)
//	{
//		int i;
//		double vz = 0;
//		if ((fl > 0) && (fl < 7))
//		{
//			for (i = 0; i < n; i++)
//			{
//				vz += MasBols[i]->get_sum(fl);
//			}
//		}
//		return vz;
//	}
//
//	void print_special()
//	{
//		int i, j, k, fl = 0, ndates = 0;
//		Person t;
//		string Mdates[30];
//		Sums Msums[30];
//		for (i = 0; i < n; i++)
//		{
//			for (j = 0; j < MasBols[i]->getN(); j++)
//			{
//				t = *MasBols[i]->getPerson(j);
//				if (ndates == 0)
//				{
//					Mdates[ndates] = t.get_mes_god();
//					Msums[ndates].days1 += t.get_sum(1);
//					Msums[ndates].sum1 += t.get_sum(2);
//					Msums[ndates].days2 += t.get_sum(3);
//					Msums[ndates].sum2 += t.get_sum(4);
//					Msums[ndates].days3 += t.get_sum(5);
//					Msums[ndates].sum3 += t.get_sum(6);
//					ndates++;
//				}
//				else
//				{
//					fl = 0;
//					for (k = 0; k < ndates; k++)
//					{
//						if (t.get_mes_god() == Mdates[k])
//						{
//							Msums[k].days1 += t.get_sum(1);
//							Msums[k].sum1 += t.get_sum(2);
//							Msums[k].days2 += t.get_sum(3);
//							Msums[k].sum2 += t.get_sum(4);
//							Msums[k].days3 += t.get_sum(5);
//							Msums[k].sum3 += t.get_sum(6);
//							fl = 1;
//						}
//					}
//					if(fl==0)
//					{
//						Mdates[ndates] = t.get_mes_god();
//						Msums[k].days1 += t.get_sum(1);
//						Msums[k].sum1 += t.get_sum(2);
//						Msums[k].days2 += t.get_sum(3);
//						Msums[k].sum2 += t.get_sum(4);
//						Msums[k].days3 += t.get_sum(5);
//						Msums[k].sum3 += t.get_sum(6);
//						ndates++;
//					}
//				}
//			}
//		}
//		for (k = 0; k < ndates; k++)
//		{
//			cout << endl << fixed << setprecision(2) << setw(70) << Mdates[k];
//			cout << fixed << setprecision(0) << setw(9) << Msums[k].days1;
//			cout << fixed << setprecision(2) << setw(12) << Msums[k].sum1;
//			cout << fixed << setprecision(0) << setw(5) << Msums[k].days2;
//			cout << fixed << setprecision(2) << setw(12) << Msums[k].sum2;
//			cout << fixed << setprecision(0) << setw(5) << Msums[k].days3;
//			cout << fixed << setprecision(2) << setw(12) << Msums[k].sum3;
//		}
//	}
//
//	string get_type()
//	{
//		return travmOrill;
//	}
//
//	int getN() { return n; }
//
//	int get_ill_type(int ind)
//	{
//		return MasBols[ind]->get_ill_type();
//	}
//
//	int get_N_persons(int ind)
//	{
//		return MasBols[ind]->getN();
//	}
//
//	Person* get_person(int ind1, int ind2)
//	{
//		return MasBols[ind1]->getPerson(ind2);
//	}
//
//	void add_person(int ind, Person o)
//	{
//		MasBols[ind]->addPerson(o);
//	}
//
//	bolezn* getBolezn(int ind)
//	{
//		return MasBols[ind];
//	}
//
//	int find_ind_type(int ind)
//	{
//		int i, vz=-1;
//		for (i = 0; i < n;i++)
//		{
//			if (MasBols[i]->get_ill_type() == ind)
//				vz = i;
//		}
//		return vz;
//	}
//
//	void addbol(bolezn b)
//	{
//		MasBols[n] = new bolezn(b);
//		n++;
//	}
//
//	void sort()
//	{
//		int i;
//		for (i = 0; i < n; i++)
//			MasBols[i]->sort();
//	}
//
//};
//
//
//class dok
//{
//private:
//	string predpr;
//	string N_per;
//	int Nmax;
//	int n;
//	Vedomost** Mvedoms;
//
//public:
//
//	dok()
//	{
//		predpr = "Net predpr";
//		N_per = "Net perioda";
//		Nmax = 5;
//		n = 0;
//		Mvedoms = new Vedomost * [Nmax];
//	}
//
//	dok(const dok& o)
//	{
//		N_per = o.N_per;
//		predpr = o.predpr;
//		Nmax = o.Nmax;
//		n = o.n;
//		Mvedoms = new Vedomost * [Nmax];
//		if (n > 0)
//			for (int i = 0; i < n; i++)
//			{
//				Mvedoms[i] = new Vedomost(*o.Mvedoms[i]);
//			}
//	}
//
//	dok(string f_name)
//	{
//		ifstream f(f_name);
//		string t, t1;
//		Nmax = 5;
//		n = 0;
//		Mvedoms = new Vedomost * [Nmax];
//		if (f.is_open())
//		{
//			int pos, pos1, fl=0, ind_bolezn=-2, znach = -2;
//			string p, t;
//			while (!f.eof())
//			{
//				getline(f, p);
//				if (p.length() > 12)
//				{
//					pos = p.find("N");
//					if (pos > 2)
//					{
//						predpr = p;
//					}
//					else
//					{
//						pos = p.find(" : ");
//						if ((pos > 5) && (pos < 35))
//						{
//							Mvedoms[n] = new Vedomost(p.substr(pos + 3, 45));
//							pos = p.find(" §  ");
//							pos1 = p.find("20");
//							N_per = p.substr(pos + 1, pos1 + 4);
//							if ((n == 0)&&(fl==0))
//							{
//								ind_bolezn = Mvedoms[n]->add_bolezn(0);
//								fl = 1;
//							}
//							n++;
//						}
//						else
//						{
//							pos = p.find("->");
//							znach = atoi(p.substr(pos + 4, 3).c_str());
//							if (pos>5)
//							{
//								ind_bolezn = Mvedoms[n-1]->add_bolezn(znach);
//							}
//							else
//							{
//								if (o_digit(p[6]) == true)
//								{
//									Mvedoms[n - 1]->add_person(ind_bolezn, p);
//								}
//							}
//						}
//					}
//				}
//			}
//		}
//		else
//		{
//			N_per = "Net perioda";
//			Mvedoms = new Vedomost * [Nmax];
//		}
//	}
//
//	~dok()
//	{
//		if (n > 0)
//			for (int i = 0; i < n; i++)
//				delete Mvedoms[i];
//		delete[]Mvedoms;
//	}
//
//	void print_v_razr(int ind)
//	{
//		Mvedoms[ind]->print_special();
//	}
//
//	int find_ind(string par)
//	{
//		int i;
//		for (i = 0; i < n; i++)
//		{
//			if (Mvedoms[i]->get_type() == par)
//				return i;
//		}
//		return -1;
//	}
//
//	void print()
//	{
//		if (n > 0)
//		{
//			for (int i = 0; i < n; i++)
//			{
//				cout << endl << endl << "\t" << predpr << endl;
//				cout << "\t\t\t\t Vedomost\n\t\t\t nachisleniya posobiya po vremennoy netrudosposobnosti" << endl;
//				cout << "\t\t " << N_per << endl;
//
//				Mvedoms[i]->print();
//				cout << endl;
//				cout << "-----------------------------------------------------------------------------------------------------------------------------------------" << endl;
//				cout << "\t\t\t\t\t\tItogo po predpriyatiyu:" << endl;
//				cout << fixed << setprecision(0) << setw(79) << Mvedoms[i]->get_sum(1);
//				cout << fixed << setprecision(2) << setw(12) << Mvedoms[i]->get_sum(2);
//				cout << fixed << setprecision(0) << setw(5)<< Mvedoms[i]->get_sum(3);
//				cout << fixed << setprecision(2) << setw(12) << Mvedoms[i]->get_sum(4);
//				cout << fixed << setprecision(0) << setw(5) << Mvedoms[i]->get_sum(5);
//				cout << fixed << setprecision(2) << setw(12)<< Mvedoms[i]->get_sum(6);
//				cout << endl << "-----------------------------------------------------------------------------------------------------------------------------------------" << endl;
//				cout << "---------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
//				cout << "\t\t\t\tV razreze raschetnikh periodov: " << endl;
//				print_v_razr(i);
//				cout << endl << "---------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
//
//			
//			}
//		}
//	}
//	dok operator=(dok o)
//	{
//		if (this != &o)
//		{
//			if (n > 0)
//				for (int i = 0; i < n; i++)
//					delete Mvedoms[i];
//			delete[]Mvedoms;
//
//			N_per = o.N_per;
//			predpr = o.predpr;
//			Nmax = o.Nmax;
//			n = o.n;
//			Mvedoms = new Vedomost * [Nmax];
//			if (n > 0)
//				for (int i = 0; i < n; i++)
//				{
//					Mvedoms[i] = new Vedomost(*o.Mvedoms[i]);
//				}
//		}
//			return *this;
//	}
//		
//	string get_per()
//	{
//		return N_per;
//	}
//	dok operator+(dok o)
//	{
//		dok tmp(*this);
//		tmp.N_per += ", ";
//		tmp.N_per += o.get_per();
//		int i, j, k, ind1, ind2;
//		string illness="";
//		int ill_type = -1;
//		
//		for (i = 0; i < o.n; i++)
//		{
//			illness = o.Mvedoms[i]->get_type();
//			ind1 = find_ind(illness);
//			if (ind1 >= 0)
//			{
//				for (j = 0; j < o.Mvedoms[ind1]->getN(); j++)
//				{
//					ill_type = o.Mvedoms[i]->get_ill_type(j);
//					ind2 = tmp.Mvedoms[i]->find_ind_type(ill_type);
//					if (ind2 >= 0)
//					{
//						for (k = 0; k < o.Mvedoms[i]->get_N_persons(j); k++) 
//						{
//							tmp.Mvedoms[ind1]->add_person(ind2, *o.Mvedoms[i]->get_person(j, k));
//						}
//					}
//					else
//					{
//						tmp.Mvedoms[ind1]->addbol(*o.Mvedoms[i]->getBolezn(j));
//					}
//				}
//			}
//		}
//		return tmp;
//	}
//
//	void sort()
//	{
//		int i;
//		for (i = 0; i < n; i++)
//			Mvedoms[i]->sort();
//	}
//};
//
//
//#define up 72
//#define down 80
//#define left_arrow 75
//#define right_arrow 77
//#define enter 13
//#define esc 27
//
//HDC hDC;
//HWND hWnd;
//RECT Rect;
//HRGN Rgn;
//HPEN hPen, hOldPen;
//HBRUSH hBrush, hOldBrush;
//HFONT hFont, hOldFont;
//LOGFONT Lf = { 0 };
//
//
//typedef struct
//{
//	int x;
//	int y;
//	int r;
//	COLORREF col, col_border;
//	char* text;
//	int sm;
//}Knopka;
//
//
//
//typedef struct
//{
//	int x[4];
//	COLORREF col;
//}Panel;
//
//
//typedef struct
//{
//	Knopka* Knop;
//	Panel Pan;
//	int n, m;
//}Menu;
//
//
//void clearscreen()
//{
//	hPen = CreatePen(PS_SOLID, 4, RGB(111, 120, 180));
//	hOldPen = (HPEN)SelectObject(hDC, hPen);
//	hBrush = CreateSolidBrush(RGB(111, 120, 180));
//	hOldBrush = (HBRUSH)SelectObject(hDC, hBrush);
//	Rectangle(hDC, Rect.left, Rect.top, Rect.right + 400, Rect.bottom + 200);
//	SelectObject(hDC, hOldPen);
//	DeleteObject(hPen);
//	SelectObject(hDC, hOldBrush);
//	DeleteObject(hBrush);
//}
//
//void panel(Panel* N)
//{
//	hPen = CreatePen(PS_SOLID, 4, RGB(255, 255, 255));
//	hOldPen = (HPEN)SelectObject(hDC, hPen);
//	hBrush = CreateSolidBrush(RGB(255, 255, 255));
//	hOldBrush = (HBRUSH)SelectObject(hDC, hBrush);
//	hFont = CreateFontIndirect(&Lf);
//	hOldFont = (HFONT)SelectObject(hDC, hFont);
//	Rectangle(hDC, N->x[0] - 4, N->x[1] - 4, N->x[0] + N->x[2] + 4, N->x[1] + N->x[3] + 4);
//	SelectObject(hDC, hOldPen);
//	DeleteObject(hPen);
//	SelectObject(hDC, hOldBrush);
//	DeleteObject(hBrush);
//
//	hPen = CreatePen(PS_SOLID, 4, RGB(0, 0, 0));
//	hOldPen = (HPEN)SelectObject(hDC, hPen);
//	hBrush = CreateSolidBrush(RGB(0, 0, 0));
//	hOldBrush = (HBRUSH)SelectObject(hDC, hBrush);
//	Rectangle(hDC, N->x[0], N->x[1], N->x[0] + N->x[2] + 4, N->x[1] + N->x[3] + 4);
//	SelectObject(hDC, hOldPen);
//	DeleteObject(hPen);
//	SelectObject(hDC, hOldBrush);
//	DeleteObject(hBrush);
//
//	hPen = CreatePen(PS_SOLID, 4, N->col);
//	hOldPen = (HPEN)SelectObject(hDC, hPen);
//	hBrush = CreateSolidBrush(N->col);
//	hOldBrush = (HBRUSH)SelectObject(hDC, hBrush);
//	Rectangle(hDC, N->x[0], N->x[1], N->x[0] + N->x[2], N->x[1] + N->x[3]);
//	SelectObject(hDC, hOldPen);
//	DeleteObject(hPen);
//}
//
//void knopka_circle(Knopka* P)
//{
//	int x = P->x;
//	int y = P->y;
//	int r = P->r;
//	int sm = P->sm;
//
//	hPen = CreatePen(PS_SOLID, 4, RGB(255, 255, 255));
//	hOldPen = (HPEN)SelectObject(hDC, hPen);
//	hBrush = CreateSolidBrush(RGB(255, 255, 255));
//	hOldBrush = (HBRUSH)SelectObject(hDC, hBrush);
//	hFont = CreateFontIndirect(&Lf);
//	hOldFont = (HFONT)SelectObject(hDC, hFont);
//	x = P->x - sm;
//	y = P->y - sm;
//
//	Ellipse(hDC, x, y, x + r, y + r);
//
//	SelectObject(hDC, hOldPen);
//	DeleteObject(hPen);
//	SelectObject(hDC, hOldBrush);
//	DeleteObject(hBrush);
//
//	hPen = CreatePen(PS_SOLID, 4, RGB(0, 0, 0));  //белое
//	hOldPen = (HPEN)SelectObject(hDC, hPen);
//	hBrush = CreateSolidBrush(RGB(0, 0, 0));
//	hOldBrush = (HBRUSH)SelectObject(hDC, hBrush);
//
//	x = P->x + sm;
//	y = P->y + sm;
//
//	Ellipse(hDC, x, y, x + r, y + r);
//	SelectObject(hDC, hOldPen);
//	DeleteObject(hPen);
//	SelectObject(hDC, hOldBrush);
//	DeleteObject(hBrush);                        //белое
//
//	hPen = CreatePen(PS_SOLID, 4, P->col);
//	hOldPen = (HPEN)SelectObject(hDC, hPen);
//	hBrush = CreateHatchBrush(HS_CROSS, P->col);
//	hOldBrush = (HBRUSH)SelectObject(hDC, hBrush);
//
//	x = P->x;
//	y = P->y;
//
//	Ellipse(hDC, x, y, x + r, y + r);
//
//	SelectObject(hDC, hOldPen);
//	DeleteObject(hPen);
//	SelectObject(hDC, hOldBrush);
//	DeleteObject(hBrush);
//
//	hPen = CreatePen(PS_DOT, 1, P->col_border);
//	hOldPen = (HPEN)SelectObject(hDC, hPen);
//	hBrush = CreateHatchBrush(HS_CROSS, P->col_border);
//	hOldBrush = (HBRUSH)SelectObject(hDC, hBrush);
//
//	Ellipse(hDC, x, y, x + r, y + r);
//
//	SelectObject(hDC, hOldPen);
//	DeleteObject(hPen);
//	SelectObject(hDC, hOldBrush);
//	DeleteObject(hBrush);
//
//	SetTextColor(hDC, RGB(0, 0, 0));
//	SetBkColor(hDC, P->col);
//	TextOut(hDC, P->x + r / 2 - sm * 2, P->y + r / 2 - sm * 2, (LPCSTR)P->text, strlen(P->text));
//	SelectObject(hDC, hOldFont);
//	DeleteObject(hFont);
//}
//
//void knopka_rect(Knopka* P)
//{
//	int x = P->x;
//	int y = P->y;
//	int r = P->r;
//	int sm = P->sm;
//
//	hPen = CreatePen(PS_SOLID, 4, RGB(255, 255, 255));
//	hOldPen = (HPEN)SelectObject(hDC, hPen);
//	hBrush = CreateSolidBrush(RGB(255, 255, 255));
//	hOldBrush = (HBRUSH)SelectObject(hDC, hBrush);
//
//	hFont = CreateFontIndirect(&Lf);
//	hOldFont = (HFONT)SelectObject(hDC, hFont);
//
//	x = P->x - sm;
//	y = P->y - sm;
//	r = P->r + sm * 2;
//
//	Rectangle(hDC, x, y, x + r, y + r);
//
//	SelectObject(hDC, hOldPen);
//	DeleteObject(hPen);
//	SelectObject(hDC, hOldBrush);
//	DeleteObject(hBrush);
//
//	hPen = CreatePen(PS_SOLID, 4, RGB(0, 0, 0));
//	hOldPen = (HPEN)SelectObject(hDC, hPen);
//	hBrush = CreateSolidBrush(RGB(0, 0, 0));
//	hOldBrush = (HBRUSH)SelectObject(hDC, hBrush);
//
//	x = P->x + 2;
//	y = P->y + 2;
//	r = P->r + sm - 2;
//
//	Rectangle(hDC, x, y, x + r, y + r);
//
//	SelectObject(hDC, hOldPen);
//	DeleteObject(hPen);
//	SelectObject(hDC, hOldBrush);
//	DeleteObject(hBrush);
//
//
//	hPen = CreatePen(PS_SOLID, 4, P->col);
//	hOldPen = (HPEN)SelectObject(hDC, hPen);
//	hBrush = CreateSolidBrush(P->col);
//	hOldBrush = (HBRUSH)SelectObject(hDC, hBrush);
//
//	x = P->x;
//	y = P->y;
//	r = P->r;
//
//	Rectangle(hDC, x, y, x + r, y + r);
//
//	SelectObject(hDC, hOldPen);
//	DeleteObject(hPen);
//	SelectObject(hDC, hOldBrush);
//	DeleteObject(hBrush);
//
//	hPen = CreatePen(PS_DOT, 1, P->col_border);
//	hOldPen = (HPEN)SelectObject(hDC, hPen);
//	hBrush = CreateHatchBrush(HS_CROSS, P->col_border);
//	hOldBrush = (HBRUSH)SelectObject(hDC, hBrush);
//
//	x = P->x;
//	y = P->y;
//	r = P->r;
//
//	Rectangle(hDC, x, y, x + r, y + r);
//
//	SelectObject(hDC, hOldPen);
//	DeleteObject(hPen);
//	SelectObject(hDC, hOldBrush);
//	DeleteObject(hBrush);
//
//
//	SetTextColor(hDC, RGB(0, 0, 0));
//	SetBkColor(hDC, P->col);
//	TextOut(hDC, P->x + r / 2 - sm * 2, P->y + r / 2 - sm * 2, (LPCSTR)P->text, strlen(P->text));
//	SelectObject(hDC, hOldFont);
//	DeleteObject(hFont);
//}
//
//Menu menu_init_vert(const char* punkt[], int l, int top, int width, int height, int n)
//{
//	int i;
//	Menu M;
//	M.n = n;
//	M.m = 0;
//	M.Pan.x[0] = l;
//	M.Pan.x[1] = top;
//	M.Pan.x[2] = width + 20;
//	M.Pan.x[3] = n * height + n * 5;
//	M.Knop = new Knopka[n];
//
//	for (i = 0; i < n; i++)
//	{
//		if (i == 0)
//		{
//			M.Knop[i].y = top + 20;
//		}
//		else
//		{
//			M.Knop[i].y = M.Knop[i - 1].y + height;
//		}
//		M.Knop[i].x = l + 20;
//
//		M.Knop[i].text = new char[strlen(punkt[i]) + 1];
//		strcpy(M.Knop[i].text, punkt[i]);
//		M.Knop[i].r = (height + width) / 3;
//		M.Knop[i].sm = 5;
//	}
//
//
//	return M;
//}
//
//void menu_del(Menu* M)
//{
//	int i;
//	for (i = 0; i < M->n; i++)
//		delete[]M->Knop[i].text;
//	delete[]M->Knop;
//}
//
//int menu_vert(Menu* M)
//{
//	int i;
//	char ch;
//	panel(&(M->Pan));
//	do
//	{
//		for (i = 0; i < M->n; i++)
//		{
//			if (M->m == i) M->Knop[i].col = RGB(111, 120, 180), M->Knop[i].col_border = RGB(255, 255, 0);
//			else M->Knop[i].col = RGB(111, 120, 180), M->Knop[i].col_border = RGB(111, 120, 180);
//			if (i % 2 == 0)knopka_rect(&(M->Knop[i]));
//			else knopka_circle(&(M->Knop[i]));
//		}
//
//		ch = _getch();
//
//		switch (ch)
//		{
//		case up: if (M->m == 0) M->m = M->n - 1;
//			   else (M->m)--;
//			break;
//
//		case down: if (M->m == M->n - 1) M->m = 0;
//				 else (M->m)++;
//
//		}
//	} while (ch != enter && ch != esc);
//	if (ch == esc) M->m = M->n - 1;
//	return M->m;
//}
//
//
//int main()
//{
//	setlocale(LC_ALL, "866");
//	hWnd = GetConsoleWindow();
//	MoveWindow(hWnd, 0, 0, 1000, 1000, FALSE);
//	hDC = GetDC(hWnd);
//	GetClientRect(hWnd, &Rect);
//	const char* s[] = { "File 1", "File 2", "1 + 2", "Exit" };
//	int m = 0, h = 180, w = 180;
//	clearscreen();
//
//
//	dok a("var16_1.TXT");
//	dok b("var16_2.TXT");
//	dok c = a + b;
//
//
//	Menu M = menu_init_vert(s, 10, 10, h, w, 4);
//	do
//	{
//		clearscreen();
//		m = menu_vert(&M);
//		switch (m)
//		{
//		case 0:
//			system("cls");
//			a.print();
//			_getch();
//			break;
//
//		case 1:
//			system("cls");
//			b.print();
//			_getch();
//			break;
//
//		case 2:
//			system("cls");
//			c.sort();
//			c.print();
//			_getch();
//			break;
//		}
//	} while (m != 3 && m != 27);
//	menu_del(&M);
//	ReleaseDC(hWnd, hDC);
//	return 0;
//}


//кто-то делал Татьяничеву
 
//#include <iostream>
//#include <string>
//#include <fstream>
//#include <iomanip>
//#include <algorithm>
//using namespace std;
//
//struct MesyacGod
//{
//	int mesyac;
//	int god;
//	int day1;
//	double count1;
//	int day2;
//	double count2;
//	int day3;
//	double count3;
//};
//
//class Stroka
//{
//public:
//	Stroka()
//	{
//		tab_nomer = 0; iniciali = ""; nomer_bol_lista = 0; vid_netrudosp = 0;
//		datanach_bol_lista = ""; datakon_bol_lista = ""; procent_posobiya = 0; data = 0;
//		summa_dnevn_posobiya = 0.0; days1 = 0; summa_posobiya = 0.0; days2 = 0;
//		summa_za_schet_predpr = 0.0; days3 = 0; summa_za_soc_straha = 0.0; mesyac = 0;
//		god = 0, znachenie = 0;
//	}
//
//	Stroka(string s)
//	{
//		int pos = s.find("€в®Ј® Ї® в Ў.­®¬Ґаг");
//		int pos1 = s.find("‚Ё¤ § Ў®«Ґў ­Ёп");
//
//		if (pos > 0)
//		{
//			data = 3;
//		}
//		else if (pos1 > 0)
//		{
//			data = 1;
//			string st = s;
//			string str1 = st.substr(pos1 + 18);
//			znachenie = stoi(str1);
//		}
//		else
//		{
//			data = 0;
//			std::replace(s.begin(), s.end(), '.', ',');
//			string str1;
//
//			str1 = s.substr(3, 4); tab_nomer = stoi(str1);
//			str1 = s.substr(8, 17); iniciali = str1;
//			std::replace(iniciali.begin(), iniciali.end(), ',', '.');
//			str1 = s.substr(29, 6); nomer_bol_lista = stoi(str1);
//			str1 = s.substr(36, 4); vid_netrudosp = stoi(str1);
//			str1 = s.substr(40, 8); datanach_bol_lista = str1;
//			str1 = s.substr(48, 9); datakon_bol_lista = str1;
//			str1 = s.substr(57, 4); procent_posobiya = stoi(str1);
//			str1 = s.substr(61, 12); summa_dnevn_posobiya = stod(str1);
//			str1 = s.substr(75, 5); days1 = stoi(str1);
//			str1 = s.substr(80, 12); summa_posobiya = stod(str1);
//			str1 = s.substr(91, 4); days2 = stoi(str1);
//			str1 = s.substr(95, 12); summa_za_schet_predpr = stod(str1);
//			str1 = s.substr(105, 5); days3 = stoi(str1);
//			str1 = s.substr(110, 12); summa_za_soc_straha = stod(str1);
//
//			int pos = 0;
//			int step = 0;
//			string znak;
//			string st = datanach_bol_lista;
//			while ((pos = st.find('/')) != string::npos) {
//				znak = st.substr(0, pos);
//				if (step == 1)
//					mesyac = stoi(znak);
//				st.erase(0, pos + 1);
//				step++;
//			}
//			god = stoi(st);
//		}
//	}
//
//	void ShowAll()
//	{
//		if (data == 0)
//		{
//			cout << "   ";
//			cout << right << std::setw(4) << tab_nomer << "  ";
//			cout << left << std::setw(19) << iniciali;
//			cout << nomer_bol_lista << "  ";
//			cout << right << std::setw(2) << vid_netrudosp << " ";
//			cout << datanach_bol_lista << " ";
//			cout << datakon_bol_lista << " ";
//			cout << right << std::setw(3) << procent_posobiya << " ";
//			cout << fixed << setprecision(2) << right << std::setw(11) << summa_dnevn_posobiya;
//			cout << right << std::setw(6) << days1 << " ";
//			cout << fixed << setprecision(2) << right << std::setw(10) << summa_posobiya;
//			cout << right << std::setw(4) << days2 << " ";
//			cout << fixed << setprecision(2) << right << std::setw(10) << summa_za_schet_predpr;
//			cout << right << std::setw(4) << days3 << " ";
//			cout << fixed << setprecision(2) << right << std::setw(11) << summa_za_soc_straha;
//			cout << endl;
//		}
//	}
//
//	int getStrokaTip() { return data; }
//	int getmesyac() { return mesyac; }
//	int getgod() { return god; }
//	int getDays1() { return days1; }
//	int getDays2() { return days2; }
//	int getDays3() { return days3; }
//	int getZnachenie() { return znachenie; }
//	double getSummaPosobiya() { return summa_posobiya; }
//	double getSummaZaSchetPredpr() { return summa_za_schet_predpr; }
//	double getSummaZaSocStraha() { return summa_za_soc_straha; }
//
//private:
//	int tab_nomer, nomer_bol_lista, vid_netrudosp, procent_posobiya, days1, days2, days3, mesyac, god, znachenie;
//	string iniciali, datanach_bol_lista, datakon_bol_lista;
//	double summa_dnevn_posobiya, summa_posobiya, summa_za_schet_predpr, summa_za_soc_straha;
//	int data;
//};
//
//class KartaPredpriyatiya
//{
//public:
//	KartaPredpriyatiya(int tp = 0)
//	{
//		t = 0; Max = 5; stroki = new Stroka * [Max];
//		type = tp;
//	}
//
//	void AddStroka(string s)
//	{
//		if (t >= Max) { this->dob_memory(); }
//		stroki[t] = new Stroka(s);
//		t++;
//	}
//
//	void ShowAll()
//	{
//		for (int i = 0; i < t; i++)
//		{
//			Stroka* r = stroki[i];
//			int typ = r->getStrokaTip();
//			if (typ == 0)
//				r->ShowAll();
//			else if (typ == 1)
//			{
//				int val = r->getZnachenie();
//				cout << "  ‚Ё¤ § Ў®«Ґў ­Ёп ->   " << val << endl;
//			}
//			else if (typ == 2)
//			{
//				double sum = 0;
//				for (int j = 0; j < i; j++)
//				{
//					if (stroki[j]->getStrokaTip() == 0)
//						sum += stroki[j]->getSummaPosobiya();
//				}
//				cout << right << std::setw(78) << "€в®Ј® Ї® в Ў.­®¬Ґаг :";
//				cout << fixed << setprecision(2) << right << std::setw(14) << sum << endl;
//			}
//		}
//		if (type == 1)
//		{
//			int count = 0;
//			double sum = 0;
//			for (int i = 0; i < t; i++)
//			{
//				if (stroki[i]->getStrokaTip() == 0)
//				{
//					count += stroki[i]->getDays1();
//					sum += stroki[i]->getSummaPosobiya();
//				}
//			}
//			cout << " ЪДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДї" << endl;
//			cout << " і  €в®Ј® Ї® ўЁ¤г § Ў®«Ґў ­Ёп" << right << std::setw(49) << count << fixed << setprecision(2) << right << std::setw(11) << sum << "                               і" << endl;
//			cout << " АДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДЩ" << endl;
//		}
//	}
//
//	void UstanovitTipKarty(int tp)
//	{
//		type = tp;
//	}
//
//	Stroka** getStroki()
//	{
//		return stroki;
//	}
//
//	int getT()
//	{
//		return t;
//	}
//private:
//	int t, Max;
//	Stroka** stroki;
//	int type;
//	void dob_memory() {
//		Stroka** tmp; int  n = Max + 5; tmp = new Stroka * [n];
//		for (int i = 0; i < Max; i++)	tmp[i] = stroki[i];
//		delete[] stroki;
//		stroki = new Stroka * [n];
//		for (int i = 0; i < Max; i++) stroki[i] = tmp[i];
//		delete[]tmp;
//		Max = n;
//	};
//};
//
//bool sravnit_dve_daty(MesyacGod a, MesyacGod b)
//{
//	if (a.god != b.god)
//		return a.god < b.god;
//	else
//		return a.mesyac < b.mesyac;
//}
//
//class Vedomost
//{
//public:
//	Vedomost()
//	{
//		t = 0; Max = 10; god = 0; mesyac = 0; proizvKarta = nullptr; obshKarty = nullptr;
//	}
//
//	Vedomost(string name)
//	{
//		t = 0; Max = 10; god = 0; mesyac = 0;
//		proizvKarta = new KartaPredpriyatiya;
//		obshKarty = new KartaPredpriyatiya * [Max];
//
//		ifstream file(name);
//
//		if (file.is_open())
//		{
//			char str[200];
//			string str1, str2;
//			int pos;
//			bool a = true;
//
//			int cnt = 0;
//			while (!file.eof())
//			{
//				file.getline(str, 200);
//				str1 = str;
//
//				if (a)
//				{
//					pos = str1.find("Їа®Ё§ў®¤бвўҐ­­лҐ ва ў¬л");
//
//					if (pos > 0)
//					{
//						str2 = str1.substr(pos + 26, 20);
//						string m = str2.substr(1, 3);
//						str2 = str2.substr(1, 22);
//						pos = str2.find(" ");
//						str2 = str2.substr(pos + 1, 4);
//						god = atoi(str2.c_str());
//						if (m == "џ­ў") { mesyac = 1; }
//						if (m == "”Ґў") { mesyac = 2; }
//						if (m == "Њ а") { mesyac = 3; }
//						if (m == "ЂЇа") { mesyac = 4; }
//						if (m == "Њ ©") { mesyac = 5; }
//						if (m == "€о­") { mesyac = 6; }
//						if (m == "€о«") { mesyac = 7; }
//						if (m == "ЂўЈ") { mesyac = 8; }
//						if (m == "‘Ґ­") { mesyac = 9; }
//						if (m == "ЋЄв") { mesyac = 10; }
//						if (m == "Ќ®п") { mesyac = 11; }
//						if (m == "„ҐЄ") { mesyac = 12; }
//
//						file.getline(str, 200);
//						file.getline(str, 200);
//						file.getline(str, 200);
//						file.getline(str, 200);
//						file.getline(str, 200);
//						file.getline(str, 200);
//						file.getline(str, 200);
//						file.getline(str, 200);
//						file.getline(str, 200);
//						file.getline(str, 200);
//						str1 = str;
//
//						while (str1.substr(0, 2) != " -" && !file.eof())
//						{
//							if (str1.size() != NULL)
//							{
//								proizvKarta->AddStroka(str1);
//							}
//							file.getline(str, 200);
//							str1 = str;
//						}
//						a = false;
//					}
//				}
//				else
//				{
//					pos = str1.find("®ЎйЁҐ § Ў®«Ґў ­Ёп");
//					if (pos > 0)
//					{
//						file.getline(str, 200);
//						file.getline(str, 200);
//						file.getline(str, 200);
//						file.getline(str, 200);
//						file.getline(str, 200);
//						file.getline(str, 200);
//						file.getline(str, 200);
//						file.getline(str, 200);
//						file.getline(str, 200);
//						file.getline(str, 200);
//						str1 = str;
//
//						KartaPredpriyatiya* card1 = new KartaPredpriyatiya(1);
//						obshKarty[t] = card1;
//						while (!file.eof())
//						{
//							if (str1.substr(0, 2) != " -" && card1 != nullptr)
//							{
//								if (str1.size() != NULL)
//								{
//									card1->AddStroka(str1);
//								}
//								file.getline(str, 200);
//								str1 = str;
//							}
//							else
//							{
//								if (card1 != nullptr)
//								{
//									card1 = nullptr;
//									file.getline(str, 200);
//									file.getline(str, 200);
//									file.getline(str, 200);
//									str1 = str;
//									if (str1.substr(0, 2) != " -" && str1.substr(0, 2) != " |")
//									{
//										t++;
//										if (t >= Max) { this->dob_memory(); }
//										card1 = new KartaPredpriyatiya(1);
//										obshKarty[t] = card1;
//									}
//								}
//								else
//								{
//									file.getline(str, 200);
//									str1 = str;
//								}
//							}
//						}
//					}
//				}
//			}
//		}
//	}
//
//	void ShowAll()
//	{
//		cout << setw(60) << "Џа®Ё§ў®¤бвўҐ­­лҐ ва ў¬л ЊҐбпж " << mesyac << " ѓ®¤ " << god << endl;
//		ShowHeader();
//		proizvKarta->ShowAll();
//		ShowProizvItogo();
//		cout << "     ЏаҐ¤бҐ¤ вҐ«м Є®¬ЁббЁЁ Ї® б®ж. бва е®ў ­Ёо" << endl;
//		cout << "     ѓ« ў­л© ЎгеЈ «вҐа" << endl;
//		cout << endl;
//		cout << setw(60) << "ЋЎйЁҐ § Ў®«Ґў ­Ёп ЊҐбпж " << mesyac << " ѓ®¤ " << god << endl;
//		ShowHeader();
//		for (int i = 0; i <= t; i++)
//		{
//			obshKarty[i]->ShowAll();
//		}
//		ShowObshItogo();
//		cout << "     ЏаҐ¤бҐ¤ вҐ«м Є®¬ЁббЁЁ Ї® б®ж. бва е®ў ­Ёо" << endl;
//		cout << "     ѓ« ў­л© ЎгеЈ «вҐа" << endl;
//	}
//
//private:
//	KartaPredpriyatiya* proizvKarta;
//	KartaPredpriyatiya** obshKarty;
//	int t, Max;
//	int god, mesyac;
//	void dob_memory() {
//		KartaPredpriyatiya** tmp; int  n = Max + 5; tmp = new KartaPredpriyatiya * [n];
//		for (int i = 0; i < Max; i++)	tmp[i] = obshKarty[i];
//		delete[] obshKarty;
//		obshKarty = new KartaPredpriyatiya * [n];
//		for (int i = 0; i < Max; i++) obshKarty[i] = tmp[i];
//		delete[]tmp;
//		Max = n;
//	};
//
//	void ShowHeader()
//	{
//		cout << " ЪДДДДДДВДДДДДДДДДДДДДДДДДДДВДДДДДВДДДВДДДДДДДДВДДДДДДДДВДДДВДДДДДДДДДДДВДДВДДВДДДДДДДДДДДВДДВДДДДДДДДДДДВДДВДДДДДДДДДДДї" << endl;
//		cout << " і      і                   іЌЋЊ…ђі‚€„і  „Ђ’Ђ  і  „Ђ’Ђ  і % і  ‘“ЊЊЂ    іЏ…і  і           і  і           і  і           і" << endl;
//		cout << " і’ЂЃ…‹.і     ”ЂЊ€‹€џ       іЃЋ‹њ-іЌ…-і ЌЂ—Ђ‹Ђ іЋЉЋЌ—Ђ- іЏЋ-і           і  і„ і   ‘“ЊЊЂ   і„ і   ‘“ЊЊЂ   і„ і   ‘“ЊЊЂ   і" << endl;
//		cout << " і      і                   іЌ€— -і’ђ“іЃЋ‹њЌ€—.іЌ€џ ЃЋ‹њі‘Ћ-і „Ќ…‚ЌЋѓЋ  іђ€іЌ і           іЌ і  ‡Ђ ‘—…’  іЌ і  ‡Ђ ‘—…’  і" << endl;
//		cout << " іЌЋЊ…ђ і    €Ќ€–€Ђ‹›       іЌЋѓЋ і„Ћ-і ‹€‘’Ђ  іЌ€—ЌЋѓЋ іЃ€џі           і  і€ і  ЏЋ‘ЋЃ€џ  і€ іЏђ…„Џђ€џ’€џі€ і‘Ћ–.‘’ђЂ•Ђ і" << endl;
//		cout << " і      і                   і‹€‘’Ђі‘Џ.і        і ‹€‘’Ђ  і   і ЏЋ‘ЋЃ€џ   іЋ„і  і           і  і           і  і           і" << endl;
//		cout << " ГДДДДДДЕДДДДДДДДДДДДДДДДДДДЕДДДДДЕДДДЕДДДДДДДДЕДДДДДДДДЕДДДЕДДДДДДДДДДДЕДДЕДДЕДДДДДДДДДДДЕДДЕДДДДДДДДДДДЕДДЕДДДДДДДДДДДґ" << endl;
//		cout << " і  1   і        2          і  3  і 4 і   5    і    6   і 7 і     8     і 9і10і    11     і12і    13     і14і    15     і" << endl;
//		cout << " АДДДДДДБДДДДДДДДДДДДДДДДДДДБДДДДДБДДДБДДДДДДДДБДДДДДДДДБДДДБДДДДДДДДДДДБДДБДДБДДДДДДДДДДДБДДБДДДДДДДДДДДБДДБДДДДДДДДДДДЩ" << endl;
//	}
//
//	void ShowProizvItogo()
//	{
//		Stroka** stroki = proizvKarta->getStroki();
//		int count1 = 0;
//		double sum1 = 0;
//		int count2 = 0;
//		double sum2 = 0;
//		int count3 = 0;
//		double sum3 = 0;
//		int cnt = 0;
//		for (int i = 0; i < proizvKarta->getT(); i++)
//		{
//			if (stroki[i]->getStrokaTip() == 0)
//			{
//				cnt++;
//				count1 += stroki[i]->getDays1();
//				sum1 += stroki[i]->getSummaPosobiya();
//				count2 += stroki[i]->getDays2();
//				sum2 += stroki[i]->getSummaZaSchetPredpr();
//				count3 += stroki[i]->getDays3();
//				sum3 += stroki[i]->getSummaZaSocStraha();
//			}
//		}
//
//		MesyacGod* my = new MesyacGod[cnt];
//		cnt = 0;
//
//		for (int i = 0; i < proizvKarta->getT(); i++)
//		{
//			if (stroki[i]->getStrokaTip() == 0)
//			{
//				bool sted = true;
//				for (int j = 0; j < i; j++)
//				{
//					if (my[j].mesyac == stroki[i]->getmesyac() && my[j].god == stroki[i]->getgod())
//						sted = false;
//				}
//				if (sted)
//				{
//					my[cnt] = MesyacGod{ stroki[i]->getmesyac(), stroki[i]->getgod(), 0, 0, 0, 0, 0, 0 };
//					cnt++;
//				}
//			}
//		}
//
//		sort(my, my + cnt, sravnit_dve_daty);
//
//		for (int i = 0; i < proizvKarta->getT(); i++)
//		{
//			if (stroki[i]->getStrokaTip() == 0)
//			{
//				for (int j = 0; j < cnt; j++)
//				{
//					if (my[j].mesyac == stroki[i]->getmesyac() && my[j].god == stroki[i]->getgod())
//					{
//						my[j].day1 += stroki[i]->getDays1();
//						my[j].count1 += stroki[i]->getSummaPosobiya();
//						my[j].day2 += stroki[i]->getDays2();
//						my[j].count2 += stroki[i]->getSummaZaSchetPredpr();
//						my[j].day3 += stroki[i]->getDays3();
//						my[j].count3 += stroki[i]->getSummaZaSocStraha();
//					}
//				}
//			}
//		}
//
//		cout << " ЪДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДї" << endl;
//		cout << " і  €в®Ј® Ї® ЇаҐ¤ЇаЁпвЁо" << right << std::setw(54) << count1 << fixed << setprecision(2) << right << std::setw(11) << sum1 << right << std::setw(4) << count2 << fixed << setprecision(2) << right << std::setw(11) << sum2 << right << std::setw(4) << count3 << fixed << setprecision(2) << right << std::setw(12) << sum3 << "і" << endl;
//		cout << " ГДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДґ" << endl;
//		cout << " і ‚ а §аҐ§Ґ а бзҐв­ле ЇҐаЁ®¤®ў:                                                                                        i" << endl;
//		for (int j = 0; j < cnt; j++)
//		{
//			if (my[j].day1 != -1)
//			{
//				int pad = my[j].mesyac < 10 ? 66 : 65;
//				cout << " і  " << std::setw(pad) << (my[j].mesyac < 10 ? "0" : "") << my[j].mesyac << '/' << my[j].god << right << std::setw(4) << my[j].day1 << fixed << setprecision(2) << right << std::setw(11) << my[j].count1 << right << std::setw(4) << my[j].day2 << fixed << setprecision(2) << right << std::setw(11) << my[j].count2 << right << std::setw(4) << my[j].day3 << fixed << setprecision(2) << right << std::setw(12) << my[j].count3 << "і" << endl;
//			}
//		}
//		cout << " АДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДЩ" << endl;
//		delete[] my;
//	}
//
//	void ShowObshItogo()
//	{
//		int count1 = 0;
//		double sum1 = 0;
//		int count2 = 0;
//		double sum2 = 0;
//		int count3 = 0;
//		double sum3 = 0;
//		int cnt = 0;
//
//		for (int j = 0; j <= t; j++)
//		{
//			KartaPredpriyatiya* ent = obshKarty[j];
//			Stroka** stroki = ent->getStroki();
//			int steps = ent->getT();
//
//			for (int i = 0; i < steps; i++)
//			{
//				if (stroki[i]->getStrokaTip() == 0)
//				{
//					cnt++;
//					count1 += stroki[i]->getDays1();
//					sum1 += stroki[i]->getSummaPosobiya();
//					count2 += stroki[i]->getDays2();
//					sum2 += stroki[i]->getSummaZaSchetPredpr();
//					count3 += stroki[i]->getDays3();
//					sum3 += stroki[i]->getSummaZaSocStraha();
//				}
//			}
//		}
//
//		MesyacGod* my = new MesyacGod[cnt];
//		cnt = 0;
//		for (int j = 0; j <= t; j++)
//		{
//			KartaPredpriyatiya* ent = obshKarty[j];
//			Stroka** stroki = ent->getStroki();
//			int steps = ent->getT();
//			for (int i = 0; i < steps; i++)
//			{
//				if (stroki[i]->getStrokaTip() == 0)
//				{
//					bool sted = true;
//					for (int j = 0; j < cnt; j++)
//					{
//						if (my[j].mesyac == stroki[i]->getmesyac() && my[j].god == stroki[i]->getgod())
//							sted = false;
//					}
//					if (sted)
//					{
//						my[cnt] = MesyacGod{ stroki[i]->getmesyac(), stroki[i]->getgod(), 0, 0, 0, 0, 0, 0 };
//						cnt++;
//					}
//				}
//			}
//		}
//
//		sort(my, my + cnt, sravnit_dve_daty);
//
//		for (int j = 0; j <= t; j++)
//		{
//			KartaPredpriyatiya* ent = obshKarty[j];
//			Stroka** stroki = ent->getStroki();
//			int steps = ent->getT();
//			for (int i = 0; i < steps; i++)
//			{
//				if (stroki[i]->getStrokaTip() == 0)
//				{
//					for (int j = 0; j < cnt; j++)
//					{
//						if (my[j].mesyac == stroki[i]->getmesyac() && my[j].god == stroki[i]->getgod())
//						{
//							my[j].day1 += stroki[i]->getDays1();
//							my[j].count1 += stroki[i]->getSummaPosobiya();
//							my[j].day2 += stroki[i]->getDays2();
//							my[j].count2 += stroki[i]->getSummaZaSchetPredpr();
//							my[j].day3 += stroki[i]->getDays3();
//							my[j].count3 += stroki[i]->getSummaZaSocStraha();
//						}
//					}
//				}
//			}
//		}
//
//		cout << " ЪДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДї" << endl;
//		cout << " і  €в®Ј® Ї® ЇаҐ¤ЇаЁпвЁо" << right << std::setw(54) << count1 << fixed << setprecision(2) << right << std::setw(11) << sum1 << right << std::setw(4) << count2 << fixed << setprecision(2) << right << std::setw(11) << sum2 << right << std::setw(4) << count3 << fixed << setprecision(2) << right << std::setw(12) << sum3 << "і" << endl;
//		cout << " ГДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДґ" << endl;
//		cout << " і ‚ а §аҐ§Ґ а бзҐв­ле ЇҐаЁ®¤®ў:                                                                                        і" << endl;
//		for (int j = 0; j < cnt; j++)
//		{
//			if (my[j].day1 != -1)
//			{
//				int pad = my[j].mesyac < 10 ? 66 : 65;
//				cout << " і  " << std::setw(pad) << (my[j].mesyac < 10 ? "0" : "") << my[j].mesyac << '/' << my[j].god << right << std::setw(4) << my[j].day1 << fixed << setprecision(2) << right << std::setw(11) << my[j].count1 << right << std::setw(4) << my[j].day2 << fixed << setprecision(2) << right << std::setw(11) << my[j].count2 << right << std::setw(4) << my[j].day3 << fixed << setprecision(2) << right << std::setw(12) << my[j].count3 << "і" << endl;
//			}
//		}
//		cout << " АДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДЩ" << endl;
//		delete[] my;
//	}
//};
//
//
//int main()
//{
//	setlocale(LC_ALL, ".866");
//	cout << "file 1:" << endl;
//	Vedomost st("C:/Users/User/OneDrive/Desktop/var16_1.TXT");
//	st.ShowAll();
//	cout << "file 2:" << endl;
//	Vedomost st1("C:/Users/User/OneDrive/Desktop/var16_2.TXT");
//	st1.ShowAll();
//	return 0;
//}


//Свириденко 2
//#include <iostream>
//#include <math.h>
//#include <conio.h>
//#include <string>
//#include <fstream>
//#include <iomanip>
//#include <locale>
//#include <windows.h>
//
//using namespace std;
//
//bool o_digit(char p)
//{
//	bool vz = false;
//	if (p > 47 && p < 58)
//	{vz = true;}
//	return vz;
//}
//
//class Zachisl
//{
//private:
//	string FIO;
//	int TN;
//	long long INN;
//	long long VidVkl;
//	double SUM;
//
//public:
//	Zachisl()
//	{
//		FIO = "NO NAME";
//		TN = -100;
//		INN = -100;
//		VidVkl = -100;
//		SUM = -100;
//	};
//	Zachisl(string str)
//	{
//		string bufstr = str;
//		int pos;
//		if (bufstr.length() > 53)
//		{
//			pos = bufstr.find("|");
//			bufstr = bufstr.substr(pos+1);
//			pos = bufstr.find("|");
//			bufstr = bufstr.substr(pos + 1, 100);
//			FIO = bufstr.substr(0, 36);
//
//			pos = bufstr.find("|");
//			bufstr = bufstr.substr(pos + 1, 100);
//			TN = atoi(bufstr.substr(0, 8).c_str());
//
//			pos = bufstr.find("|");
//			bufstr = bufstr.substr(pos + 1, 100);
//			INN = atoll(bufstr.substr(1, 10).c_str());
//
//			pos = bufstr.find("|");
//			bufstr = bufstr.substr(pos + 1, 100);
//			VidVkl = atoll(bufstr.substr(0, 17).c_str());
//
//			pos = bufstr.find("|");
//			bufstr = bufstr.substr(pos + 1, 100);
//			SUM = atof(bufstr.substr(0, 12).c_str());
//		}
//	};
//	~Zachisl() {};
//
//	Zachisl(Zachisl& o)
//	{
//		FIO = o.FIO;
//		TN = o.TN;
//		INN = o.INN;
//		VidVkl = o.VidVkl;
//		SUM = o.SUM;
//	}
//	void print()
//	{
//		cout << fixed << right << setw(40) << FIO;
//		cout<< " |" << left << setw(8) << TN << " |" << right << setw(12) << INN << " |" << right << setw(18) << VidVkl << " |" << right << setw(13) << SUM << " |" << endl;
//	}
//	double getSUM()
//	{
//		return SUM;
//	}
//};
//
//class Vedomost
//{
//private:
//	string Predpr;
//	string AT;
//	int Nmax;
//	int n;
//	Zachisl** MZach;
//public:
//	Vedomost()
//	{ 
//		Predpr = "NO PREDPR";
//		AT = "NO AT";
//
//	Nmax = 400; n = 0; MZach = new Zachisl * [Nmax];
//	};
//
//	Vedomost(string str1, string str2)
//	{
//		Nmax = 400;
//		n = 0;
//		MZach = new Zachisl * [Nmax];
//		if (str1.length() > 20 && str1.length() > 20)
//		{
//			Predpr = str1;
//			AT = str2;
//		}
//		else
//		{
//			Predpr = "NO PREDPR";
//			AT = "NO AT";
//			Nmax = 400; n = 0;
//			MZach = new Zachisl * [Nmax];
//		}
//	};
//	~Vedomost() {
//		if (n > 0)
//			for (int i = 0; i < n; i++)
//				delete MZach[i];
//		delete[]MZach;
//	};
//
//	Vedomost(Vedomost& o)
//	{
//		Predpr = o.Predpr;
//		Nmax = o.Nmax;
//		n = o.n;
//		MZach = new Zachisl * [Nmax];
//		if (n > 0)
//			for (int i = 0; i < n; i++)
//			{
//				MZach[i] = new Zachisl(*o.MZach[i]);
//			}
//	}
//
//	void print()
//	{
//		cout << "Predpr: " << Predpr << endl << "AT: " << AT << endl;
//		cout << "------------------------------------------------------------------------------------------------------------ " << endl;
//		cout << "| NOM |                                         |         |             |                   |              |" << endl;
//		cout << "| P/P |                   FIO                   |   TN    |     INN     |      VidVkl       |      SUM     |" << endl;
//		cout << "|     |                                         |         |             |                   |              |" << endl;
//		cout << "|----------------------------------------------------------------------------------------------------------|" << endl;
//		cout << "|  1  |                    2                    |    3    |      4      |         5         |       6      |" << endl;
//		cout << "|----------------------------------------------------------------------------------------------------------|" << endl;
//		double summa = 0;
//		double summ = 0;
//		if (n > 0)
//		{
//			for (int i = 0; i < n; i++)
//			{
//				cout << "|" << right << setw(5) << i + 1 << "|";
//				MZach[i]->print();
//				summ += MZach[i]->getSUM();
//				if (((i % 50 == 0) || (i + 1 == n)) && (i!=0))
//				{
//					cout << "|----------------------------------------------------------------------------------------------------------|" << endl;
//					cout << "Summa po listu: " << fixed << setprecision(2) << right << setw(83) << summ << endl<<endl;
//					cout << "|----------------------------------------------------------------------------------------------------------|" << endl;
//					cout << right << setw(83) << "List " << i / 50 + 1<<endl;
//					cout << "|----------------------------------------------------------------------------------------------------------|" << endl;
//					cout << "|  1  |                    2                    |    3    |      4      |         5         |       6      |" << endl;
//					cout << "|----------------------------------------------------------------------------------------------------------|" << endl;
//
//					
//				}
//				summa += summ;
//				summ = 0;
//			}
//		}
//		cout << "|----------------------------------------------------------------------------------------------------------|" << endl;
//		cout << "  Itogo po dokumentu:  ";
//		cout << fixed << setprecision(2) << right << setw(83) << summa;
//	}
//
//	void dobZach(string str)
//	{
//		if (n < Nmax)
//		{
//			MZach[n] = new Zachisl(str);
//			n++;
//		}
//	}
//};
//
//class dok
//{
//private:
//	string Period;
//	int Nmax;
//	int n;
//	Vedomost** Mved;
//
//public:
//
//	dok()
//	{
//		Period = "Net perioda";
//		Nmax = 5;
//		n = 0;
//		Mved = new Vedomost * [Nmax];
//	}
//
//	dok(const dok& o)
//	{
//		Period = o.Period;
//		Nmax = o.Nmax;
//		n = o.n;
//		Mved = new Vedomost * [Nmax];
//		if (n > 0)
//			for (int i = 0; i < n; i++)
//			{
//				Mved[i] = new Vedomost(*o.Mved[i]);
//			}
//	}
//
//	dok(string f_name)
//	{
//		ifstream f(f_name);
//		string p, v;
//		Nmax = 5;
//		n = 0;
//		Mved = new Vedomost * [Nmax];
//		if (f.is_open())
//		{
//			int i = 0, pos, pos1;
//
//			while (!f.eof())
//			{
//				getline(f, p);
//				if (p.length() > 6)
//				{
//					pos = p.find(" ѓЏ ");// " ГП "
//					if (pos > 7)
//					{
//						p = p.substr(pos, 60);
//						getline(f, v);
//						pos1 = v.find(" Ђ’ "); // " АТ "
//						v = v.substr(pos1, 60);
//						Mved[n] = new Vedomost(p, v);
//						n++;
//					}
//					else
//					{
//						if (o_digit(p[5]) == true)
//						{
//							Mved[n - 1]->dobZach(p);
//						}
//						else
//							if (o_digit(p[4]) == true && o_digit(p[5]) == false && o_digit(p[6]) == true)
//								Period = p.substr(3, 8);
//					}
//
//				}
//			}
//		}
//		else
//		{
//			Period = "Net perioda";
//		}
//	}
//
//	~dok()
//	{
//		if (n > 0)
//			for (int i = 0; i < n; i++)
//				delete Mved[i];
//		delete[]Mved;
//	}
//
//	void print()
//	{
//		cout << "\n" << "\t\t Period:  " << Period << endl;
//		if (n > 0)
//		{
//			for (int i = 0; i < n; i++)
//			{
//				Mved[i]->print();
//				cout << endl << endl << endl;
//			}
//		}
//	}
//};
//
//int main()
//{
//	setlocale(LC_ALL, "866");
//	dok a("var15_1.TXT");
//	//dok b("var15_2.TXT");
//	a.print();
//	//b.print();
//	_getch();
//}





//Свириденко 3
#include <iostream>
#include <math.h>
#include <conio.h>
#include <string>
#include <fstream>
#include <iomanip>
#include <locale>
#include <windows.h>

using namespace std;

bool o_digit(char p)
{
	bool vz = false;
	if (p > 47 && p < 58)
	{
		vz = true;
	}
	return vz;
}

class Zachisl
{
private:
	string FIO;
	int TN;
	long long INN;
	long long VidVkl;
	double SUM;

public:
	Zachisl()
	{
		FIO = "NO NAME";
		TN = -100;
		INN = -100;
		VidVkl = -100;
		SUM = -100;
	};
	Zachisl(string str)
	{
		string bufstr = str;
		int pos;
		if (bufstr.length() > 53)
		{
			pos = bufstr.find("|");
			bufstr = bufstr.substr(pos + 1);
			pos = bufstr.find("|");
			bufstr = bufstr.substr(pos + 1, 100);
			FIO = bufstr.substr(0, 36);

			pos = bufstr.find("|");
			bufstr = bufstr.substr(pos + 1, 100);
			TN = atoi(bufstr.substr(0, 8).c_str());

			pos = bufstr.find("|");
			bufstr = bufstr.substr(pos + 1, 100);
			INN = atoll(bufstr.substr(1, 10).c_str());

			pos = bufstr.find("|");
			bufstr = bufstr.substr(pos + 1, 100);
			VidVkl = atoll(bufstr.substr(0, 17).c_str());

			pos = bufstr.find("|");
			bufstr = bufstr.substr(pos + 1, 100);
			SUM = atof(bufstr.substr(0, 12).c_str());
		}
	};
	~Zachisl() {};

	Zachisl(Zachisl& o)
	{
		FIO = o.FIO;
		TN = o.TN;
		INN = o.INN;
		VidVkl = o.VidVkl;
		SUM = o.SUM;
	}
	void print()
	{
		cout << fixed << right << setw(40) << FIO;
		cout << " |" << left << setw(8) << TN << " |" << right << setw(12) << INN << " |" << right << setw(18) << VidVkl << " |" << right << setw(13) << SUM << " |" << endl;
	}
	double getSUM()
	{
		return SUM;
	}
	int getTN()
	{
		return TN;
	}

	void summarize(double p)
	{
		SUM += p;
	}

	Zachisl* getObj()
	{
		return this;
	}
};

class Vedomost
{
private:
	string Predpr;
	string AT;
	int Nmax;
	int n;
	Zachisl** MZach;
public:
	Vedomost()
	{
		Predpr = "NO PREDPR";
		AT = "NO AT";

		Nmax = 400; n = 0; MZach = new Zachisl * [Nmax];
	};

	Vedomost(string str1, string str2)
	{
		Nmax = 400;
		n = 0;
		MZach = new Zachisl * [Nmax];
		if (str1.length() > 20 && str1.length() > 20)
		{
			Predpr = str1;
			AT = str2;
		}
		else
		{
			Predpr = "NO PREDPR";
			AT = "NO AT";
			Nmax = 400; n = 0;
			MZach = new Zachisl * [Nmax];
		}
	};
	~Vedomost() {
		if (n > 0)
			for (int i = 0; i < n; i++)
				delete MZach[i];
		delete[]MZach;
	};

	Vedomost(Vedomost& o)
	{
		Predpr = o.Predpr;
		AT = o.AT;
		Nmax = o.Nmax;
		n = o.n;
		MZach = new Zachisl * [Nmax];
		if (n > 0)
			for (int i = 0; i < n; i++)
			{
				MZach[i] = new Zachisl(*o.MZach[i]);
			}
	}

	void print()
	{
		cout << "Predpr: " << Predpr << endl << "AT: " << AT << endl;
		cout << "------------------------------------------------------------------------------------------------------------ " << endl;
		cout << "| NOM |                                         |         |             |                   |              |" << endl;
		cout << "| P/P |                   FIO                   |   TN    |     INN     |      VidVkl       |      SUM     |" << endl;
		cout << "|     |                                         |         |             |                   |              |" << endl;
		cout << "|----------------------------------------------------------------------------------------------------------|" << endl;
		cout << "|  1  |                    2                    |    3    |      4      |         5         |       6      |" << endl;
		cout << "|----------------------------------------------------------------------------------------------------------|" << endl;
		double summa = 0;
		double summ = 0;
		if (n > 0)
		{
			for (int i = 0; i < n; i++)
			{
				cout << "|" << right << setw(5) << i + 1 << "|";
				MZach[i]->print();
				summ += MZach[i]->getSUM();
				summa += MZach[i]->getSUM();
				if (((i+1) % 50 == 0) || (i == n))
				{
					if (i != 0)
					{
						cout << "|----------------------------------------------------------------------------------------------------------|" << endl;
						cout << "Summa po listu: " << fixed << setprecision(2) << right << setw(83) << summ << endl << endl;
						cout << "|----------------------------------------------------------------------------------------------------------|" << endl;
						if (i + 1 != n)
						{
							cout << right << setw(83) << "List " << i / 50 + 1 << endl;
							cout << "|----------------------------------------------------------------------------------------------------------|" << endl;
							cout << "|  1  |                    2                    |    3    |      4      |         5         |       6      |" << endl;
							cout << "|----------------------------------------------------------------------------------------------------------|" << endl;
						}
					}
						summ = 0;
				}
				
			}
		}
		cout << "|----------------------------------------------------------------------------------------------------------|" << endl;
		cout << "  Itogo po dokumentu:  ";
		cout << fixed << setprecision(2) << right << setw(83) << summa;
	}

	void dobZach(string str)
	{
		if (n < Nmax)
		{
			MZach[n] = new Zachisl(str);
			n++;
		}
	}

	int getN() { return n; }

	int getTN (int j)
	{
		return MZach[j]->getTN();
	}

	int findZach(int p)
	{
		for (int i = 0; i < n; i++)
		{
			if (MZach[i]->getTN() == p)
				return i;
		}
		return -1;
	}
	double getSUM(int j)
	{
		return MZach[j]->getSUM();
	}

	void summarize(int i, double znach)
	{
		MZach[i]->summarize(znach);
	}

	Zachisl* getObj(int i)
	{
		return MZach[i]->getObj();
	}

	void addZach(Zachisl p)
	{
		if (n + 1 < Nmax)
		{
			MZach[n] = new Zachisl(p);
			n++;
		}
	}
};

class dok
{
private:
	string Period;
	int Nmax;
	int n;
	Vedomost** Mved;

public:

	dok()
	{
		Period = "Net perioda";
		Nmax = 5;
		n = 0;
		Mved = new Vedomost * [Nmax];
	}

	dok(const dok& o)
	{
		Period = o.Period;
		Nmax = o.Nmax;
		n = o.n;
		Mved = new Vedomost * [Nmax];
		if (n > 0)
			for (int i = 0; i < n; i++)
			{
				Mved[i] = new Vedomost(*o.Mved[i]);
			}
	}

	dok(string f_name)
	{
		ifstream f(f_name);
		string p, v;
		Nmax = 5;
		n = 0;
		Mved = new Vedomost * [Nmax];
		if (f.is_open())
		{
			int i = 0, pos, pos1;

			while (!f.eof())
			{
				getline(f, p);
				if (p.length() > 6)
				{
					pos = p.find(" ѓЏ ");// " ГП "
					if (pos > 7)
					{
						p = p.substr(pos, 60);
						getline(f, v);
						pos1 = v.find(" Ђ’ "); // " АТ "
						v = v.substr(pos1, 60);
						Mved[n] = new Vedomost(p, v);
						n++;
					}
					else
					{
						if (o_digit(p[5]) == true)
						{
							Mved[n - 1]->dobZach(p);
						}
						else
							if (o_digit(p[4]) == true && o_digit(p[5]) == false && o_digit(p[6]) == true)
								Period = p.substr(3, 8);
					}

				}
			}
		}
		else
		{
			Period = "Net perioda";
		}
	}

	~dok()
	{
		if (n > 0)
			for (int i = 0; i < n; i++)
				delete Mved[i];
		delete[]Mved;
	}

	void print()
	{
		cout << "\n" << "\t\t Period:  " << Period << endl;
		if (n > 0)
		{
			for (int i = 0; i < n; i++)
			{
				Mved[i]->print();
				cout << endl << endl << endl;
			}
		}
	}


	dok operator=(dok o)
	{
		if (this != &o)
		{
			if (n > 0)
				for (int i = 0; i < n; i++)
					delete Mved[i];
			delete[]Mved;
				
			Period = o.Period;
			Nmax = o.Nmax;
			n = o.n;
			Mved = new Vedomost * [Nmax];
			if (n > 0)
				for (int i = 0; i < n; i++)
				{
					Mved[i] = new Vedomost(*o.Mved[i]);
				}
		}
		return *this;
	}
				
	dok operator+(dok o)
	{
		dok tmp(*this);
		int i, j, ind;
		tmp.Period += " and ";
		tmp.Period += o.Period;
		int TN;
		for (i = 0; i < n; i++)
		{
			for (j = 0; j < o.Mved[i]->getN(); j++)
			{
				TN = o.Mved[i]->getTN(j);
				ind = Mved[i]->findZach(TN);
				if (ind >= 0)
				{
					double znach = o.Mved[i]->getSUM(j);
					tmp.Mved[i]->summarize(ind, znach);
				}
				else
				{
					tmp.Mved[i]->addZach(*o.Mved[i]->getObj(j));
				}
			}
		}
		return tmp;
	}
};

int main()
{
	setlocale(LC_ALL, "866");
	dok a("var15_1.TXT");
	dok b("var15_2.TXT");
	a.print();
	b.print();
	//dok c = a + b;
	//c.print();
	_getch();
}






//Зинченко 2/3
/*
#include <iostream>
#include <math.h>
#include <conio.h>
#include <string>
#include <fstream>
#include <iomanip>
#include <locale>
#include <windows.h>

using namespace std;

bool o_digit(char p)
{
	bool vz = false;
	if (p > 47 && p < 58)
	{
		vz = true;
	}
	return vz;
}

class Persona
{
private:
	//Первая таблица
	int TN;
	string FIO;
	double vsego;
	double zp;
	double BLnsPR;
	double BLssPR;
	double BLnsF;
	double BLssF;
	double proch1;

	//Вторая таблица
	double PodNalog;
	double PNzpl;
	double PNblNS;
	double PNblSS;
	double ESV_36;
	double ESVblNS;

	double ESVblSS;
	double ESV_26;

	double I_508;
	double I_509;
	double I_560;
	double I_568;
	double I_569;
	double proch2;

public:
	Persona()
	{	
		TN = 0;
		FIO = "NO FIO";
		vsego = 0;
		zp = 0;

		BLnsPR = 0;
		BLssPR = 0;
		BLnsF = 0;
		BLssF = 0;
		proch1 = 0;

		//---------

		PodNalog = 0;
		PNzpl = 0;
		PNblNS = 0;
		PNblSS = 0;
		ESV_36 = 0;
		ESVblNS = 0;

		ESVblSS = 0;
		ESV_26 = 0;

		I_508 = 0;
		I_509 = 0;
		I_560 = 0;
		I_568 = 0;
		I_569 = 0;
		proch2 = 0;
	};

	Persona(string str)
	{
		int pos; 
		if (str.length() > 113)
		{
			TN = atoi(str.substr(7, 6).c_str());
			FIO = str.substr(13, 21);
			vsego = atof(str.substr(33, 13).c_str());
			zp = atof(str.substr(45, 9).c_str());

			BLnsPR = atof(str.substr(65, 9).c_str());
			BLssPR = atof(str.substr(75, 9).c_str());
			BLnsF = atof(str.substr(85, 9).c_str());
			BLssF = atof(str.substr(95, 9).c_str());
			proch1 = atof(str.substr(105, 9).c_str());
		}
	};
	~Persona() {};

	Persona(Persona& o)
	{
		TN = o.TN;
		FIO = o.FIO;
		vsego = o.vsego;
		zp = o.zp;

		BLnsPR = o.BLnsPR;
		BLssPR = o.BLssPR;
		BLnsF = o.BLnsF;
		BLssF = o.BLssF;
		proch1 = o.proch1;

		PodNalog = o.PodNalog;
		PNzpl = o.PNzpl;
		PNblNS = o.PNblNS;
		PNblSS = o.PNblSS;
		ESV_36 = o.ESV_36;
		ESVblNS = o.ESVblNS;

		ESVblSS = o.ESVblSS;
		ESV_26 = o.ESV_26;

		I_508 = o.I_508;
		I_509 = o.I_509;
		I_560 = o.I_560;
		I_568 = o.I_568;
		I_569 = o.I_569;
		proch2 = o.proch2;
	}
	void print1()
	{
		cout << right << setw(6) << TN;
		cout << right << setw(22) << FIO;
		cout << right << setw(11) << fixed <<setprecision(2) << vsego;
		if (zp > 0)
			cout << right << setw(10) << zp;
		else
			cout << "          ";
		if (BLnsPR > 0)
			cout << right << setw(10) << BLnsPR;
		else
			cout << "          ";
		if (BLssPR > 0)
			cout << right << setw(10) << BLssPR;
		else
			cout << "          ";
		if (BLnsF > 0)
			cout << right << setw(10) << BLnsF;
		else
			cout << "          ";
		if (BLssF > 0)
			cout << right << setw(10) << BLssF;
		else
			cout << "          ";
		if (proch1 > 0)
			cout << right << setw(10) << proch1;
		else
			cout << "          ";
		cout <<"  |" << endl;
	}

	void print2()
	{
		cout << right << setw(6) << TN;
		cout << right << setw(10) << vsego;
		if (PodNalog > 0)
			cout << right << setw(10) << PodNalog;
		else
			cout << "          ";
		if (PNzpl != 0)
			cout << right << setw(10) << PNzpl;
		else
			cout << "          ";
		if (PNblNS != 0)
			cout << right << setw(10) << PNblNS;
		else
			cout << "          ";
		if (PNblSS != 0)
			cout << right << setw(10) << PNblSS;
		else
			cout << "          ";
		if (ESV_36 != 0)
			cout << right << setw(10) << ESV_36;
		else
			cout << "          ";
		if (ESVblNS != 0)
			cout << right << setw(10) << ESVblNS;
		else
			cout << "          ";

		if (BLnsPR != 0)
			cout << right << setw(10) << fixed << setprecision(2) << BLnsPR*0.02;
		else
			cout << "          ";
		if (BLnsF != 0)
			cout << right << setw(10) << fixed << setprecision(2) << BLnsF * 0.02;
		else
			cout << "          ";


		if (ESVblSS != 0)
			cout << right << setw(10) << ESVblSS;
		else
			cout << "          ";


		if (BLssPR != 0)
			cout << right << setw(10) <<fixed<< setprecision(2) << BLssPR * 0.02;
		else
			cout << "          ";
		if (BLssF != 0)
			cout << right << setw(10) << fixed << setprecision(2) << BLssF * 0.02;
		else
			cout << "          ";


		if (ESV_26 != 0)
			cout << right << setw(10) << ESV_26;
		else
			cout << "          ";
		if (I_508 != 0)
			cout << right << setw(10) << I_508;
		else
			cout << "          ";
		if (I_509 != 0)
			cout << right << setw(10) << I_509;
		else
			cout << "          ";
		if (I_560 != 0)
			cout << right << setw(10) << I_560;
		else
			cout << "          ";
		if (I_568 != 0)
			cout << right << setw(10) << I_568;
		else
			cout << "          ";
		if (I_569 != 0)
			cout << right << setw(10) << I_569;
		else
			cout << "          ";
		if (proch2 != 0)
			cout << right << setw(10) << proch2;
		else
			cout << "          ";
		cout << "  |" << endl;
	}

	void add(string str)
	{
		PodNalog = atof(str.substr(24, 9).c_str());
		PNzpl = atof(str.substr(33, 10).c_str());
		PNblNS = atof(str.substr(44, 10).c_str());
		PNblSS = atof(str.substr(54, 10).c_str());
		ESV_36 = atof(str.substr(64, 10).c_str());
		ESVblNS = atof(str.substr(74, 10).c_str());

		ESVblSS = atof(str.substr(104, 10).c_str());
		ESV_26 = atof(str.substr(134, 10).c_str());

		I_508 = atof(str.substr(144, 10).c_str());
		I_509 = atof(str.substr(154, 10).c_str());
		I_560 = atof(str.substr(164, 10).c_str());
		I_568 = atof(str.substr(174, 10).c_str());
		I_569 = atof(str.substr(184, 10).c_str());
		proch2 = atof(str.substr(194, 10).c_str());
	}

	void summ(Persona& o)
	{
		vsego += o.vsego;
		zp += o.zp;

		BLnsPR += o.BLnsPR;
		BLssPR += o.BLssPR;
		BLnsF += o.BLnsF;
		BLssF += o.BLssF;
		proch1 += o.proch1;

		PodNalog += o.PodNalog;
		PNzpl += o.PNzpl;
		PNblNS += o.PNblNS;
		PNblSS += o.PNblSS;
		ESV_36 += o.ESV_36;
		ESVblNS += o.ESVblNS;

		ESVblSS += o.ESVblSS;
		ESV_26 += o.ESV_26;

		I_508 += o.I_508;
		I_509 += o.I_509;
		I_560 += o.I_560;
		I_568 += o.I_568;
		I_569 += o.I_569;
		proch2 += o.proch2;
	}

	int getTN()
	{
		return TN;
	}

	Persona* getObj()
	{
		return this;
	}

	double getVS()
	{
		return vsego;
	}
	double getZP()
	{
		return zp;
	}
	double getBLnsPR()
	{
		return BLnsPR;
	}
	double getBLssPR()
	{
		return BLssPR;
	}
	double getBLnsF()
	{
		return BLnsF;
	}
	double getBLssF()
	{
		return BLssF;
	}
	double getProch1()
	{
		return proch1;
	}




	double getPodNalog()
	{
		return PodNalog;
	}
	double getPNzpl()
	{
		return PNzpl;
	}
	double getPNblNS()
	{
		return PNblNS;
	}
	double getPNblSS()
	{
		return PNblSS;
	}
	double getESV_36()
	{
		return ESV_36;
	}
	double getESVblNS()
	{
		return ESVblNS;
	}
	double getESVblSS()
	{
		return ESVblSS;
	}
	double getESV_26()
	{
		return ESV_26;
	}
	double getI_508()
	{
		return I_508;
	}
	double getI_509()
	{
		return I_509;
	}
	double getI_560()
	{
		return I_560;
	}
	double getI_568()
	{
		return I_568;
	}
	double getI_569()
	{
		return I_569;
	}
	double getProch2()
	{
		return proch2;
	}


};

class dok
{
private:
	int Nmax;
	int n;
	Persona** Mpersonas;

public:

	dok()
	{
		Nmax = 70;
		n = 0;
		Mpersonas = new Persona * [Nmax];
	}

	dok(const dok& o)
	{
		Nmax = o.Nmax;
		n = o.n;
		Mpersonas = new Persona * [Nmax];
		if (n > 0)
			for (int i = 0; i < n; i++)
			{
				Mpersonas[i] = new Persona(*o.Mpersonas[i]);
			}
	}

	dok(string f_name)
	{
		ifstream f(f_name);
		string p;
		Nmax = 70;
		n = 0;
		Mpersonas = new Persona * [Nmax];
		if (f.is_open())
		{
			int i, pos, buf;

			while (!f.eof())
			{
				getline(f, p);
				if ((p.length() > 10) && (p.length() <120) && (o_digit(p[4]) == true))
				{
					Mpersonas[n] = new Persona(p);
					n++;
				}
				else 
				{
					if ((p.length() > 200) && (o_digit(p[4]) == true))
					{
						int bufTN = 0;
						bufTN = atoi(p.substr(7, 6).c_str());
						if (bufTN > 0)
						{
							for (i = 0; i < n; i++)
							{
								if (bufTN == Mpersonas[i]->getTN())
									Mpersonas[i]->add(p);
							}

						}
						///////////////
					}
				}

			}
		}
	}

	~dok()
	{
		if (n > 0)
			for (int i = 0; i < n; i++)
				delete Mpersonas[i];
		delete[]Mpersonas;
	}


	void print()
	{
		double itVS = 0, itZP = 0, itBLnsPR = 0, itBLssPR = 0, itBLnsF = 0, itBLssF = 0, itProch1 = 0;//1 table
		double itPodNalog = 0, itPNzpl = 0, itPNblNS = 0, itPNblSS = 0, itESV_36 = 0, itESVblNS = 0;
		double procBLnsPR = 0, procBLnsF = 0, procBLssPR = 0, procBLssF = 0; //%2...
		double itESVblSS = 0, itESV_26 = 0, itI_508 = 0, itI_509 = 0, itI_560 = 0, itI_568 = 0, itI_569 = 0, itproch2 = 0;
		if (n > 0)
		{
			cout << endl;
			cout << "----------------------------------------------------------------------------------------------------------"<<endl;
			cout << "|  N | TN |       FIO           |  Vsego  |    ZP     | BLnsPR |  BLssPR |  BLnsF  |  BLssF  |   Proch   |"<<endl;
			cout << "----------------------------------------------------------------------------------------------------------" << endl;

			for (int i = 0; i < n; i++)
			{
				cout << right << setw(5)  << i + 1;
				Mpersonas[i]->print1();

				itVS += Mpersonas[i]->getVS();
				itZP += Mpersonas[i]->getZP();
				itBLnsPR += Mpersonas[i]->getBLnsPR();
				itBLssPR += Mpersonas[i]->getBLssPR();
				itBLnsF += Mpersonas[i]->getBLnsF();
				itBLssF += Mpersonas[i]->getBLssF();
				itProch1 += Mpersonas[i]->getProch1();
			}
			cout << "----------------------------------------------------------------------------------------------------------" << endl;
			cout << "Itogo:                            " << right << setw(10) << itVS << right << setw(10) << itZP << right << setw(10) << itBLnsPR << right << setw(10) << itBLssPR << right << setw(10) << itBLnsF << right << setw(10) << itBLssF << right << setw(10) << itProch1 <<endl;
			cout << "----------------------------------------------------------------------------------------------------------" << endl;

			cout << endl;																				
			cout << "-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
			cout << "|  N | TN  |  Vsego  | PodNalog |  PNzpl |  PNblNS |  PNblSS |  ESV_36  |  ESVblNS  | 2%BLnsPR| 2%BLnsF |ESVblSS| 2%BLssPR | 2%BLssF |  ESV_26 |  I_508 |   I_509  |  I_560  |  I_568  |  I_569  |  proch2  |  " << endl;
			cout << "-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;

			for (int i = 0; i < n; i++)
			{
				cout << right << setw(5) << i+1;
				Mpersonas[i]->print2();
				itPodNalog += Mpersonas[i]->getPodNalog();
				itPNzpl += Mpersonas[i]->getPNzpl();
				itPNblNS += Mpersonas[i]->getPNblNS();
				itPNblSS += Mpersonas[i]->getPNblSS();
				itESV_36 += Mpersonas[i]->getESV_36();
				itESVblNS += Mpersonas[i]->getESVblNS();

				procBLnsPR += 0.02* Mpersonas[i]->getBLnsPR();
				procBLnsF += 0.02 * Mpersonas[i]->getBLnsF();

				itESVblSS += Mpersonas[i]->getESVblSS();

				procBLssPR += 0.02 * Mpersonas[i]->getBLssPR();
				procBLssF += 0.02 * Mpersonas[i]->getBLssF();

				itESV_26 += Mpersonas[i]->getESV_26();
				itI_508 += Mpersonas[i]->getI_508();
				itI_509 += Mpersonas[i]->getI_509();
				itI_560 += Mpersonas[i]->getI_560();
				itI_568 += Mpersonas[i]->getI_568();
				itI_569 += Mpersonas[i]->getI_569();
				itproch2 += Mpersonas[i]->getProch2();
			}

			cout << "----------------------------------------------------------------------------------------------------------" << endl;
			cout << "Itogo:    |" << right << setw(10) << itVS << right << setw(10) << itPodNalog << right << setw(10) << itPNzpl << right << setw(10) << itPNblNS << right << setw(10) << itPNblSS << right << setw(10) << itESV_36 << right << setw(10) << itESVblNS << right << setw(10) << procBLnsPR << right << setw(10) <<  procBLnsF << right << setw(10) << itESVblSS << right << setw(10)<< procBLssPR << right << setw(10) << procBLssF << right << setw(10) << itESV_26 << right << setw(10) << itI_508 << right << setw(10) << itI_509 << right << setw(10) << itI_560 << right << setw(10) << itI_568 << right << setw(10) << itI_569 << right << setw(10) << itproch2<<endl;
			cout << "----------------------------------------------------------------------------------------------------------" << endl;


		}
		else
		{
			cout << endl << "No data" << endl;
		}
	}


	dok operator=(dok o)
	{
		if (this != &o)
		{
			if (n > 0)
				for (int i = 0; i < n; i++)
					delete Mpersonas[i];
			delete[]Mpersonas;
						
			Nmax = o.Nmax;
			n = o.n;
			Mpersonas = new Persona * [Nmax];
			if (n > 0)
				for (int i = 0; i < n; i++)
				{
					Mpersonas[i] = new Persona(*o.Mpersonas[i]);
				}
		}
		return *this;
	}
						
	dok operator+(dok o)
	{
		dok tmp(*this);
		int i, j, flag;
		int TN;
		for (i = 0; i < o.n; i++)
		{
			TN = o.Mpersonas[i]->getTN();
			flag = 0;
			for (j = 0; j < n; j++)
			{
				if (TN == Mpersonas[j]->getTN())
				{
					Mpersonas[j]->summ(*o.Mpersonas[i]);
					flag = 1;
					break;
				}
			}
			if (flag == 0)
			{
				Mpersonas[n] = o.Mpersonas[i];
				n += 1;
			}
		}

		return *this;
	}

};

int main()
{
	setlocale(LC_ALL, "866");
	dok a("var34_1.TXT");
	dok b("var34_2.TXT");
	a.print();
	b.print();
	dok c = a + b;
	c.print();
	_getch();
}
*/


//Калинина, 35 вариант
/*
#include <iostream>
#include <math.h>
#include <conio.h>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;

bool o_digit(char p)
{
	bool vz = false;
	if (p > 47 && p < 58)
	{
		vz = true;
	}
	return vz;
}

struct Itog
{
	int key;
	int sum1;
	double sum2;
};

class Zapis
{
private:
	string FIO;
	long long Nstrah;
	string Nlist;
	int PrichNerab;
	string PerNerab;
	int NdnVsego;
	int NdnFond;
	double Summa;
	double SummaFond;


public:
	Zapis()
	{
		FIO = "NO FIO";
		Nstrah=0;
		Nlist="No nomer";
		PrichNerab=0;
		PerNerab="No per";
		NdnVsego=0;
		NdnFond=0;
		Summa=0;
		SummaFond=0;
	};

	Zapis(string str)
	{
		FIO = str.substr(5, 20);
		Nstrah = atoll(str.substr(26, 11).c_str());
		Nlist = str.substr(38, 6);
		PrichNerab = atoi(str.substr(46, 9).c_str());
		PerNerab = str.substr(55, 17);
		NdnVsego = atoi(str.substr(74, 5).c_str());
		NdnFond = atoi(str.substr(80, 8).c_str());
		Summa = atof(str.substr(89, 10).c_str());
		SummaFond = atof(str.substr(100, 13).c_str());
	};
	~Zapis() {};

	Zapis(Zapis& o)
	{
		FIO = o.FIO;
		Nstrah = o.Nstrah;
		Nlist = o.Nlist;
		PrichNerab = o.PrichNerab;
		PerNerab = o.PerNerab;
		NdnVsego = o.NdnVsego;
		NdnFond = o.NdnFond;
		Summa = o.Summa;
		SummaFond = o.SummaFond;
	}

	void print()
	{
		cout << right << setw(22) << FIO <<"|";
		cout << right << setw(11) << fixed << setprecision(2) << Nstrah << "|";
		cout << right << setw(11) << Nlist << "|";
		cout << right << setw(11) << PrichNerab << "|";
		cout << right << setw(20) << PerNerab << "|";
		cout << right << setw(11) << fixed << setprecision(2) << NdnVsego << "|";
		cout << right << setw(11) << fixed << setprecision(2) << NdnFond << "|";
		cout << right << setw(11) << fixed << setprecision(2) << Summa << "|";
		cout << right << setw(11) << fixed << setprecision(2) << SummaFond << "|" <<endl;
	}

	Zapis* getObj()
	{
		return this;
	}

	string getFIO()
	{
		return FIO;
	}

	int getNdnVsego()
	{
		return NdnVsego;
	}

	int getNdnFond()
	{
		return NdnFond;
	}

	double getSumma()
	{
		return Summa;
	}

	double getSummaFond()
	{
		return SummaFond;
	}

	double getPrichNerab()
	{
		return PrichNerab;
	}

};


class dok
{
private:
	int Nmax;
	int n;
	Zapis** masZapis;

public:

	dok()
	{
		Nmax = 50;
		n = 0;
		masZapis = new Zapis * [Nmax];
	}

	dok(const dok& o)
	{
		Nmax = o.Nmax;
		n = o.n;
		masZapis = new Zapis * [Nmax];
		if (n > 0)
			for (int i = 0; i < n; i++)
			{
				masZapis[i] = new Zapis(*o.masZapis[i]);
			}
	}

	dok(string f_name)
	{
		ifstream f(f_name);
		string p;
		Nmax = 50;
		n = 0;
		masZapis = new Zapis * [Nmax];
		
		if (f.is_open())
		{
			int i, pos, buf;

			while (!f.eof())
			{
				getline(f, p);
				if (p.length() ==113 && o_digit(p[3]) == true)
				{
					masZapis[n]=new Zapis(p);
					n++;
				}
			}
			
		}
	}

	~dok()
	{
		if (n > 0)
			for (int i = 0; i < n; i++)
				delete masZapis[i];
		delete[]masZapis;
	}
	
	int summa1()
	{
		int sum = 0;
		for (int i = 0; i < n; i++)
		{
			sum += masZapis[i]->getNdnVsego();
		}
		return sum;
	}

	int summa2()
	{
		int sum = 0;
		for (int i = 0; i < n; i++)
		{
			sum += masZapis[i]->getNdnFond();
		}
		return sum;
	}

	double summa3()
	{
		double sum = 0;
		for (int i = 0; i < n; i++)
		{
			sum += masZapis[i]->getSumma();
		}
		return sum;
	}

	double summa4()
	{
		double sum = 0;
		for (int i = 0; i < n; i++)
		{
			sum += masZapis[i]->getSummaFond();
		}
		return sum;
	}
	
	Itog count()
	{
		Itog itog = { 0,0,0 };
		itog.sum1 = 5;
		
		for (int i = 0; i < n; i++)
		{
			MasStranits[i]->
		}
		return itog;
	}
	
	Itog vich(int par)
	{
		Itog itog = {par,0,0};
		for (int i = 0; i < n; i++)
		{
			itog.sum1 += MasStranits[i]->vich(par).sum1;
			itog.sum2 += MasStranits[i]->vich(par).sum2;
		}
		return itog;
	}
	
	

	bool hasPrich(int par)
	{
		bool b = false;
		for (int i = 0; i < n; i++)
		{
			if (MasStranits[i]->hasPrich(par))
			{
				b = true;
				break;
			}
		}
		return b;
	}

	bool hasPrich(int par)
	{
		bool b = false;
		for (int i = 0; i < n; i++)
		{
			if (masZapis[i]->getPrichNerab() == par)
			{
				b = true;
				break;
			}
		}
		return b;
	}


	Itog vich(int par)
	{
		Itog itog = { par,0,0 };
		for (int i = 0; i < n; i++)
		{
			if (masZapis[i]->getPrichNerab() == par)
			{
				itog.sum1 += masZapis[i]->getNdnFond();
				itog.sum2 += masZapis[i]->getSummaFond();
			}
		}
		return itog;
	}

	void print()
	{
		cout <<"("<< n << "/" << Nmax<<") Stranits";
		if (n > 0)
		{
			cout << endl;
			cout << "-------------------------------------------------------------------------------------------------------------------------------------" << endl;
			cout << "|  N |       FIO           |  Nstrah   |    Nlist   |PrichNerab|      PerNerab      |  NdnVsego |  NdnFond  |   Summa   | SummaFond |" << endl;
			cout << "-------------------------------------------------------------------------------------------------------------------------------------" << endl;

			for (int i = 0; i < n; i++)
			{
				cout << right << setw(5) << i + 1;
				masZapis[i]->print();
			}
			cout << "-------------------------------------------------------------------------------------------------------------------------------------" << endl;
			cout << "Itogo po predpriyatiyu:                                                             |      " << summa1() << " |       " << summa2() << " |  " << summa3() << "  |  " << summa4() << "  " << endl;
			cout << "-------------------------------------------------------------------------------------------------------------------------------------" << endl;
			
			for (int i = 0; i < 11; i++)
			{
					if (hasPrich(i))
					{
						Itog itog = vich(i);
						cout <<"                                                             " << itog.key <<"                                          " << itog.sum1<<"                  " << itog.sum2<<endl;
						cout << "                                                 ------------------------------------------------------------------------------------" << endl;
					}
				
			}
			

		}
		else
		{
			cout << endl << "No data" << endl;
		}
	}

	
	dok operator=(dok o)
	{
		if (this != &o)
		{
			if (n > 0)
				for (int i = 0; i < n; i++)
					delete masZapis[i];
			delete[]masZapis;

			Nmax = o.Nmax;
			n = o.n;
			masZapis = new Zapis * [Nmax];
			if (n > 0)
				for (int i = 0; i < n; i++)
				{
					masZapis[i] = new Zapis(*o.masZapis[i]);
				}
		}
		return *this;
	}
	
	dok operator+(dok o)
	{
		dok tmp(*this);
		int i, j;
		for (i = 0; i < o.n; i++)
		{
			tmp.masZapis[tmp.n] = new Zapis(*o.masZapis[i]);
			tmp.n++;
		}
		for (j = 0; j < tmp.n; j++)
		for (i = 0; i < tmp.n - 1; i++)
		{
			Zapis* zap = new Zapis();
			if (tmp.masZapis[i]->getPrichNerab() > tmp.masZapis[i + 1]->getPrichNerab())
			{
				zap = tmp.masZapis[i];
				tmp.masZapis[i] = tmp.masZapis[i + 1];
				tmp.masZapis[i + 1] = zap;
			}
		}
		return tmp;
	}

};

int main()
{
	setlocale(LC_ALL, "866");
	dok a("var35_1.TXT");
	dok b("var35_2.TXT");
	int key = 0;
	do
	{
		cout << "PRESS ANY KEY TO CONTINUE" << endl;
		key = 0;
		_getch();
		do
		{
			key = 0;
			cin.clear();
			system("cls");
			cout << "1 - Dokument 1" << endl;
			cout << "2 - Dokument 2" << endl;
			cout << "3 - Dokument 1 + Dokument 2" << endl;
			cout << "4 - Exit" << endl;
			cin >> key;
			if (!cin)
			{
				cout << "error";
				key = 4;
				break;
			}
		} while (key<1||key>4);

		if (key == 1)
		{
			cout << "DOKUMENT 1" << endl;
			a.print();
		}
		if (key == 2)
		{
			cout << endl << endl << "DOKUMENT 2" << endl;
			b.print();
		}
		if (key == 3)
		{
			cout << endl << endl << "DOKUMENT 3" << endl;
			dok c = a + b;
			c.print();
		}
	} while (key!=4);
}
*/