program Kalorijos;
   const  duom = 'Duomenys.txt';
   const  rez = 'Rezultatai.txt';
   var  a, r, b : real;    // angliavandeniø, riebalø ir baltymø kiekis procentais
     ak, rk, bk : integer; // viename grame angliavandeniø, riebalø ir baltymø esantis kalorijø skaièius
              k : integer; // þmogaus per parà suvartojamas kcal kiekis
     gr, gb, ga : real;   // riebalø, baltymø ir angliavandeniø kiekis gramais
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

