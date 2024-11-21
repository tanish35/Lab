DECLARE
    day_name VARCHAR2(10);
BEGIN
    SELECT TO_CHAR(SYSDATE, 'DAY') 
    INTO day_name
    FROM DUAL;
    DBMS_OUTPUT.PUT_LINE(day_name);
    day_name:=TRIM(day_name);   -- required if padding is there does not run
    
    IF day_name IN ('SATURDAY', 'SUNDAY') THEN
        DBMS_OUTPUT.PUT_LINE('Today falls on a weekend.');
    ELSIF day_name in('THURSDAY') THEN
        DBMS_OUTPUT.PUT_LINE('Today is THURSDAY.');
    ELSE
        DBMS_OUTPUT.PUT_LINE('Today is NOT THURSDAY.');
    END IF;
END;

