DO language plpgsql $$
DECLARE
    i   BIGINT;
    sum BIGINT;
BEGIN
    sum := 0;
    FOR i IN
        SELECT rg0downlink FROM cdr
    LOOP
        sum := sum + i;
    END LOOP;
    RAISE NOTICE 'sum = %', sum;
END
$$;
