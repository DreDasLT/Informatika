program Kalorijos;
   const  duom = 'Duomenys.txt';
   const  rez = 'Rezultatai.txt';
   var  a, r, b : real;    // angliavandeni�, riebal� ir baltym� kiekis procentais
     ak, rk, bk : integer; // viename grame angliavandeni�, riebal� ir baltym� esantis kalorij� skai�ius
              k : integer; // �mogaus per par� suvartojamas kcal kiekis
     gr, gb, ga : real;   // riebal�, baltym� ir angliavandeni� kiekis gramais
         fd, fr : text;
begin
  Assign (fd, duom);
  Reset (fd);
  Readln (fd, a, r, b);
  ReadLn (fd, ak, rk, bk);
  ReadLn (fd, k);
  Close (fd);
  gr := (k * r * 0.01) / rk;
  gb := (k * b * 0.01) / bk;
  ga := (k * a * 0.01) / ak;
  Assign (fr, rez);
  Rewrite (fr);
  WriteLn (fr, ga : 0 : 2);
  WriteLn (fr, gr : 0 : 2);
  WriteLn (fr, gb : 0 : 2);
  Close (fr);
end.

