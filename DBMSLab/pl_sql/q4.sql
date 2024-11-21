DECLARE
    a NUMBER ;
    r NUMBER;
    ans NUMBER;
BEGIN
  a:=563847384;
  ans:=0;
  WHILE a!=0 LOOP
    r:=MOD(a,10);
    ans:=ans*10+r;
    a:=TRUNC(a/10);
  END LOOP;
  dbms_output.put_line('The ans is '||ans);
END;

