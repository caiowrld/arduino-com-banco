CREATE DATABASE estufa;
USE estufa;
CREATE TABLE registroLeds(
id INT PRIMARY KEY AUTO_INCREMENT,
	cor TEXT NOT NULL,
    dataHoraRegistro DATETIME
);

SELECT * FROM registroLeds;