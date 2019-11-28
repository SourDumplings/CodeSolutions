CREATE TABLE person (
    driver_id VARCHAR(50),
    `name` VARCHAR(50),
    `address` VARCHAR(50),
    PRIMARY KEY (driver_id)
);

CREATE TABLE car (
    license VARCHAR(50),
    model VARCHAR(50),
    `year` INT,
    PRIMARY KEY (license)
);

CREATE TABLE accident (
    report_number INT,
    `date` DATE,
    `location` VARCHAR(50),
    PRIMARY KEY (report_number)
);

CREATE TABLE owns (
    driver_id VARCHAR(50),
    license VARCHAR(50),
    PRIMARY KEY (driver_id, license),
    FOREIGN KEY (driver_id) REFERENCES person(driver_id),
    FOREIGN KEY (license) REFERENCES car(license)
);

CREATE TABLE participated (
    report_number INT,
    license VARCHAR(50),
    driver_id VARCHAR(50),
    damage_amount INT,
    PRIMARY KEY (report_number, license),
    FOREIGN KEY (license) REFERENCES car(license),
    FOREIGN KEY (driver_id) REFERENCES person(driver_id),
    FOREIGN KEY (report_number) REFERENCES accident(report_number)
);