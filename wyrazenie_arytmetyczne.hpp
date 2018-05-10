#ifndef WYRAZENIA_HPP_INCLUDED
#define WYRAZENIA_HPP_INCLUDED
#include <vector>
#include <algorithm>
#include <string>
//**********************************************************
//##########################################################
//**********************************************************
namespace wyrazenie_arytmetyczne {

	class wyrazenie
	{
	public:
		virtual ~wyrazenie() {}
	public:
		virtual double oblicz() = 0;
		virtual std::string opis() = 0;
	};
	//**********************************************************
	//##########################################################
	//**********************************************************

	class liczba : public wyrazenie
	{
	private:
		double x;
	public:
		liczba(double xx) : x(xx) {}
	public:
		double oblicz() override;
		std::string opis() override;
	};
	//**********************************************************
	//##########################################################
	//**********************************************************

	class stala : public wyrazenie
	{
		std::string nazwa;
	public:
		stala(std::string naz) : nazwa(naz) {}
	public:
		std::string opis() override;
	};
	//**********************************************************
	//##########################################################
	//**********************************************************
	class pi : public stala
	{
	public:
		pi() : stala("PI") {}
	public:
		double oblicz() override;
	};
	//**********************************************************
	//##########################################################
	//**********************************************************
	class e : public stala
	{
	public:
		e() : stala("E") {}
	public:
		double oblicz() override;
	};

	class fi : public stala
	{
	public:
		fi() : stala("FI") {}
	public:
		double oblicz() override;
	};
	//**********************************************************
	//##########################################################
	//**********************************************************
	//**********************************************************
	//##########################################################
	//**********************************************************
	class zmienna : public wyrazenie
	{
	private:
		std::string nazwa;
		static std::vector<std::pair<std::string, double> > v;
	public:
		zmienna(std::string n) : nazwa(n) { }

		static void ustaw(std::string nazwa_zm, double wartosc)
		{
			for (int i = 0; i < v.size(); i++)
				if (v[i].first == nazwa_zm)
				{
					v[i].second = wartosc;
					return;
				}
			v.push_back(make_pair(nazwa_zm, wartosc));
		}

		double oblicz() override
		{
			for (int i = 0; i < v.size(); i++)
				if (v[i].first == nazwa)
					return v[i].second;

			return 0;
		}

		std::string opis() override
		{
			return nazwa;
		}
	};



	//**********************************************************
	//##########################################################
	//**********************************************************
	//**********************************************************
	//##########################################################
	//**********************************************************
	//**********************************************************
	//##########################################################
	//**********************************************************

	class operator1arg : public wyrazenie
	{
	protected:
		wyrazenie *arg1;
	public:
		operator1arg(wyrazenie *a1);
		~operator1arg() override;
	};
	//**********************************************************
	//##########################################################
	//**********************************************************

	class sinus : public operator1arg
	{
	public:
		sinus(wyrazenie *a1) : operator1arg(a1) {}
	public:
		double oblicz() override;
		std::string opis() override;
	};
	
	//**********************************************************
	//##########################################################
	//**********************************************************
	class bezwzgl : public operator1arg
	{
	public:
		bezwzgl(wyrazenie *a1) : operator1arg(a1) {}
	public:
		double oblicz()    override ;
		std::string opis() override ;

	};
	//**********************************************************
	//##########################################################
	//**********************************************************
	class cosinus : public operator1arg
	{
	public:
		cosinus(wyrazenie *a1) : operator1arg(a1) {}
	public:
		double oblicz() override;
		std::string opis() override;
	};
	
	
	//**********************************************************
	//##########################################################
	//**********************************************************
	class przeciw : public operator1arg
	{
	public:
		przeciw(wyrazenie *a1) : operator1arg(a1) {}
	public:
		double oblicz() override;
		std::string opis() override;

	};
	//**********************************************************
	//##########################################################
	//**********************************************************
	class exp1 : public operator1arg
	{
	public:
		exp1(wyrazenie *a1) : operator1arg(a1) {}
	public:
		double oblicz() override;
		std::string opis() override;

	};
	//**********************************************************
	//##########################################################
	//**********************************************************
	class odwrot : public operator1arg
	{
	public:
		odwrot(wyrazenie *a1) : operator1arg(a1) {}
	public:
		double oblicz() override;
		std::string opis() override;

	};
	//**********************************************************
	//##########################################################
	//**********************************************************
	class ln : public operator1arg
	{
	public:
		ln(wyrazenie *a1) : operator1arg(a1) {}
	public:
		double oblicz() override;
		std::string opis() override;

	};
	//**********************************************************
	//##########################################################
	//**********************************************************
	class operator2arg : public operator1arg
	{
	protected:
		wyrazenie *arg2;
	public:
		operator2arg(wyrazenie *a1, wyrazenie *a2)  ;
		~operator2arg() override;
	};
	//**********************************************************
	//##########################################################
	//**********************************************************

	class dodaj : public operator2arg
	{

	public:
		dodaj(wyrazenie *a1, wyrazenie *a2) : operator2arg(a1, a2 ) {}
	public:
		double oblicz() override;
		std::string opis() override;
	};
	//**********************************************************
	//##########################################################
	//**********************************************************

	class logarytm : public operator2arg
	{

	public:
		logarytm(wyrazenie *a1, wyrazenie *a2) : operator2arg(a1, a2) {}
	public:
		double oblicz() override    ;
		std::string opis() override ;
	};
	//**********************************************************
	//##########################################################
	//**********************************************************

	class odejmij : public operator2arg
	{

	public:
		odejmij(wyrazenie *a1, wyrazenie *a2) : operator2arg(a1, a2) {}
	public:
		double oblicz() override;
		std::string opis() override;
	};
	//**********************************************************
	//##########################################################
	//**********************************************************
	class mnoz : public operator2arg
	{

	public:
		mnoz(wyrazenie *a1, wyrazenie *a2) : operator2arg(a1, a2) {}
	public:
		double oblicz() override;
		std::string opis() override;
	};
	//**********************************************************
	//##########################################################
	//**********************************************************
	class dziel : public operator2arg
	{

	public:
		dziel(wyrazenie *a1, wyrazenie *a2) : operator2arg(a1, a2) {}
	public:
		double oblicz()    override;
		std::string opis() override;
	};
	//**********************************************************
	//##########################################################
	//**********************************************************
	class potega : public operator2arg
	{

	public:
		potega(wyrazenie *a1, wyrazenie *a2) : operator2arg(a1, a2) {}
	public:
		double oblicz()    override;
		std::string opis() override;
	};
} // namespace wyrazenia_arytmetyczne

#endif // WYRAZENIA_HPP_INCLUDED
