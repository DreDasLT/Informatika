program Aritmetika;
   const  duom = 'Duomenys.txt';
   const  rez = 'Rezultatai.txt';
//-------------------------------------------------
function Tikrinimas (a, b, c : integer; o : char) : boolean;
   begin
      if (o = '+') and (a + b = c) then Tikrinimas := true
        else if (o = '-') and (a - b = c) then Tikrinimas := true
              else if (o = '*') and (a * b = c) then Tikrinimas := true
                   else if (o = '/') and (a mod b = 0) and (a div b = c) then Tikrinimas := true
                   else Tikrinimas := false;
   end;
//-------------------------------------------------
   var            n : integer;    // uþduoèiø skaièius
            a, b, c : integer;    // sveikieji skaièiai
     t1, t2, t3, t4 : boolean;    // rezultatai
                  i : integer;
             fd, fr : text;
begin
  Assign (fd, duom);
  Reset (fd);
  Assign (fr, rez);
  Rewrite (fr);
  Readln (fd, n);
  for i := 1 to n do
     begin
        ReadLn (fd, a, b, c);
        t1 := Tikrinimas (a, b, c, '+');
        t2 := Tikrinimas (a, b, c, '-');
        t3 := Tikrinimas (a, b, c, '*');
        t4 := Tikrinimas (a, b, c, '/');
        if t1 then WriteLn (fr, a, ' + ', b, ' = ', c);
        if t2 then WriteLn (fr, a, ' - ', b, ' = ', c);
        if t3 then WriteLn (fr, a, ' * ', b, ' = ', c);
        if t4 then WriteLn (fr, a, ' / ', b, ' = ', c);
        if (t1 = false) and (t2 = false) and (t3 = false) and (t4 = false) then WriteLn (fr, a, ' ', b, ' ', c, ' KLAIDINGA');
     end;
  Close(fd);
  Close (fr);
end.

