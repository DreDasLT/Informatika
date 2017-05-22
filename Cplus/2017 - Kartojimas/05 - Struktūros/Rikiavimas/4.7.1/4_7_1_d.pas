program Trumpiausios_keliones;
  const  duom = 'Duomenys.txt';
  const  rez = 'Rezultatai.txt';
  type     Marsrutai = record
                      pav : string[15];
                     v, m : integer;
                   end;
      Masyvas1 = array[1..100] of Marsrutai;
//---------------------------------------------
      Etapas = record
                      pav : string[20];
                        t : integer;
                        M : Masyvas1;
                   end;
      Masyvas2 = array[1..100] of Etapas;
//-------------------------------------------------
procedure Rikiavimas (var X : Masyvas1; n : integer);
   var i, j, m : integer; t : Marsrutai;
begin
   for i := 1 to n - 1 do
      begin
        m := i;
        for j := i + 1 to n do
          if (X[j].v * 60 + X[j].m < X[m].v * 60 + X[m].m) then m := j;
        t := X[i]; X[i] := X[m]; X[m] := t;
      end;
end;
//-------------------------------------------------
procedure Skaitymas (var E : Masyvas2; var n : integer);
   var          i, j : integer;
                  MM : Masyvas1;
                  fd : text;
begin
  Assign (fd, duom);
  Reset (fd);
  ReadLn (fd, n);
  for i := 1 to n do
    begin
       ReadLn (fd, E[i].pav, E[i].t);
       for j := 1 to E[i].t do
         begin
           Read (fd, MM[j].pav);
           ReadLn (fd, MM[j].v, MM[j].m);
         end;
        Rikiavimas (MM, E[i].t);
        for j := 1 to E[i].t do
           begin
               E[i].M[j].pav := MM[j].pav;
               E[i].M[j].v := MM[j].v;
               E[i].M[j].m := MM[j].m;
           end;
    end;
  Close (fd);
end;
//--------------------------------------------------
procedure Rasymas(E : Masyvas2; n : integer);
   var fr : text; i, j : integer;
begin
  Assign (fr, rez);
  Rewrite (fr);
  for i := 1 to n do
     begin
        WriteLn (fr, E[i].pav);
        for j := 1 to E[i].t do
           WriteLn (fr, E[i].M[j].pav, E[i].M[j].v, ' ', E[i].M[j].m);
     end;
  Close (fr);
end;
//-------------------------------------------------
   var       n : integer;
             E : Masyvas2;
begin
  Skaitymas(E, n);
  Rasymas(E, n);
end.
