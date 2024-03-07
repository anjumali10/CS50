-- Keep a log of any SQL queries you execute as you solve the mystery.

-- List the discription of all the crime scene reports on that particular day at Humphrey Street
SELECT
    description
FROM
    crime_scene_reports
WHERE
    MONTH = 7
    AND DAY = 28
    AND YEAR = 2021
    AND street = 'Humphrey Street';

-- Show the transcript of interviews from some witnesses there
SELECT
    transcript
FROM
    interviews
WHERE
    MONTH = 7
    AND DAY = 28
    AND YEAR = 2021;

SELECT
    name
FROM
    people
WHERE
    name IN (
        -- List the people who exit the bakery parking lot at that particular time
        SELECT
            name
        FROM
            people
        WHERE
            license_plate IN (
                SELECT
                    license_plate
                FROM
                    bakery_security_logs
                WHERE
                    MONTH = 7
                    AND DAY = 28
                    AND YEAR = 2021
                    AND HOUR = 10
                    AND MINUTE >= 15
                    AND MINUTE <= 25
            )
    )
    AND name IN (
        -- List the people who conducted transactions at that time on Leggett Street
        SELECT
            name
        FROM
            people
        WHERE
            id IN (
                SELECT
                    person_id
                FROM
                    bank_accounts
                WHERE
                    account_number IN (
                        SELECT
                            account_number
                        FROM
                            atm_transactions
                        WHERE
                            MONTH = 7
                            AND DAY = 28
                            AND YEAR = 2021
                            AND atm_location = 'Leggett Street'
                            AND transaction_type = 'withdraw'
                    )
            )
    )
    AND name IN (
        -- List the people who made phone call less than a minute at that particular time
        SELECT
            name
        FROM
            people
        WHERE
            phone_number IN (
                SELECT
                    caller
                FROM
                    phone_calls
                WHERE
                    MONTH = 7
                    AND DAY = 28
                    AND YEAR = 2021
                    AND duration < 60
            )
    )
    AND name IN (
        -- List the people who have flights the next day.
        SELECT
            name
        FROM
            people
        WHERE
            passport_number IN (
                SELECT
                    passport_number
                FROM
                    passengers
                WHERE
                    flight_id IN (
                        SELECT
                            id
                        FROM
                            flights
                        WHERE
                            MONTH = 7
                            AND DAY = 29
                            AND YEAR = 2021
                        ORDER BY
                            HOUR
                        LIMIT
                            1
                    )
            )
    );


-- Extract the recipient of Bruce's call
SELECT
    name
FROM
    people
WHERE
    phone_number IN (
        SELECT
            receiver
        FROM
            phone_calls
        WHERE
            caller IN (
                SELECT
                    phone_number
                FROM
                    people
                WHERE
                    name = 'Bruce'
            )
            AND duration < 60
            AND MONTH = 7
            AND DAY = 28
            AND YEAR = 2021
    );

-- Extract the city to which Bruce goes
SELECT
    city
FROM
    airports
WHERE
    id IN (
        SELECT
            destination_airport_id
        FROM
            flights
        WHERE
            id IN (
                SELECT
                    flight_id
                FROM
                    passengers
                WHERE
                    passport_number IN (
                        SELECT
                            passport_number
                        FROM
                            people
                        WHERE
                            name = 'Bruce'
                    )
            )
    );
