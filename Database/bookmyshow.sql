-- MySQL dump 10.13  Distrib 8.0.16, for Win64 (x86_64)
--
-- Host: localhost    Database: bookmyshow
-- ------------------------------------------------------
-- Server version	8.0.16

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
 SET NAMES utf8mb4 ;
/*!40103 SET @OLD_TIME_ZONE=@@TIME_ZONE */;
/*!40103 SET TIME_ZONE='+00:00' */;
/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;

--
-- Table structure for table `booking`
--

DROP TABLE IF EXISTS `booking`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
 SET character_set_client = utf8mb4 ;
CREATE TABLE `booking` (
  `BookingId` int(11) NOT NULL AUTO_INCREMENT,
  `UserId` bigint(20) NOT NULL,
  `ShowId` int(11) NOT NULL,
  `NoOfSeatsBooked` int(11) NOT NULL,
  `AmountPaid` int(11) NOT NULL,
  PRIMARY KEY (`BookingId`),
  KEY `UserId` (`UserId`),
  KEY `ShowId` (`ShowId`),
  CONSTRAINT `booking_ibfk_1` FOREIGN KEY (`UserId`) REFERENCES `user` (`MobileNo`),
  CONSTRAINT `booking_ibfk_2` FOREIGN KEY (`ShowId`) REFERENCES `shows` (`Id`)
) ENGINE=InnoDB AUTO_INCREMENT=2 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `booking`
--

LOCK TABLES `booking` WRITE;
/*!40000 ALTER TABLE `booking` DISABLE KEYS */;
INSERT INTO `booking` VALUES (1,123456789,1,2,500);
/*!40000 ALTER TABLE `booking` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `movie`
--

DROP TABLE IF EXISTS `movie`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
 SET character_set_client = utf8mb4 ;
CREATE TABLE `movie` (
  `Id` bigint(20) NOT NULL,
  `MovieName` char(50) NOT NULL,
  `Languages` text NOT NULL,
  `MovieType` char(20) DEFAULT NULL,
  `ReleaseDate` date NOT NULL,
  `Rating` float DEFAULT NULL,
  `StarCasts` text,
  PRIMARY KEY (`Id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `movie`
--

LOCK TABLES `movie` WRITE;
/*!40000 ALTER TABLE `movie` DISABLE KEYS */;
INSERT INTO `movie` VALUES (1,'Avangers','English','Action','2019-04-26',4.3,'Chris Evans, Robert Downey'),(2,'How to train your dragon','English','Adventure','2019-04-21',4.3,'Jay Baruchel, Gerand Butler'),(3,'Kalank','Hindi','Drama','2019-04-17',2.8,'Varun Dhawan, Alia Bhatt'),(4,'Jersey','Telugu','Drama','2019-04-19',3.8,'Nani, Sardha'),(5,'Kavaludaari','Kannada','Crime','2019-04-12',3.2,'Rishi, Anant Nag'),(6,'Chhota Bheem','English','Action','2019-05-10',4.3,'Rajiv Chilaka, Robert Downey'),(7,'The Curse Of The Weeping Woman','English','Horror','2019-04-19',2.5,'Linda, Patricia'),(8,'Shazam!','English','Action','2019-04-05',4.3,'Mark	Strong, Zachrya Levi'),(9,'Dumbo','English','Action','2019-03-29',3.5,'Eva, Green'),(10,'Student of the Year 2','Hindi','Drama','2019-05-10',5.3,'Tiger Shroff, Ananya Pandey'),(11,'Godzilla 2','English','Adventure','2019-05-31',3.3,'Vera Farmiga, Kyle Chandler'),(12,'X-Men','English','Action','2019-08-26',1.3,'Evans,  Downey'),(13,'Bharat','Hindi','Action','2019-07-26',2.3,'Salman Khan'),(14,'Kabir Singh','Hindi','Action','2019-06-26',3.3,'John Abraham'),(15,'Spider-Man Far from home','English','Action','2019-05-26',4.6,'Chris , Robert'),(16,'The Lion King','English','Action','2019-08-23',4.5,'Vere munda'),(17,'Super 30','Hindi','Action','2019-05-16',4.4,'Hritik Roshan'),(18,'Shahoo','Telugu','Action','2019-07-09',4.2,'Anmay Mishra'),(19,'Rambo','Hidni','Action','2019-04-21',4.1,'Tiger Sharoff'),(20,'Street Dancer','Hindi','Action','2019-06-26',3.3,'Varun Dhawan');
/*!40000 ALTER TABLE `movie` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `shows`
--

DROP TABLE IF EXISTS `shows`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
 SET character_set_client = utf8mb4 ;
CREATE TABLE `shows` (
  `Id` int(11) NOT NULL,
  `MovieId` bigint(20) NOT NULL,
  `TheaterId` bigint(20) NOT NULL,
  `ShowsTime` int(11) NOT NULL,
  PRIMARY KEY (`Id`),
  UNIQUE KEY `duplicate_all` (`TheaterId`,`ShowsTime`,`MovieId`),
  UNIQUE KEY `duplicate_two` (`TheaterId`,`ShowsTime`),
  KEY `MovieId` (`MovieId`),
  KEY `ShowsTime` (`ShowsTime`),
  CONSTRAINT `shows_ibfk_1` FOREIGN KEY (`MovieId`) REFERENCES `movie` (`Id`),
  CONSTRAINT `shows_ibfk_2` FOREIGN KEY (`TheaterId`) REFERENCES `theater` (`Id`),
  CONSTRAINT `shows_ibfk_3` FOREIGN KEY (`ShowsTime`) REFERENCES `showtime` (`Id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `shows`
--

LOCK TABLES `shows` WRITE;
/*!40000 ALTER TABLE `shows` DISABLE KEYS */;
INSERT INTO `shows` VALUES (1,1,1,1),(2,2,1,2),(3,3,1,3),(22,14,2,1),(30,5,3,1),(21,15,3,3),(20,16,4,2),(32,2,4,3),(19,17,5,1),(33,12,5,2),(34,11,5,3),(35,10,6,1),(38,5,6,2),(18,18,6,3),(17,19,7,2),(29,6,7,3),(16,20,8,1),(36,9,8,2),(27,9,8,3),(26,10,9,2),(15,19,9,3),(37,8,10,3),(7,12,11,1),(14,18,11,2),(24,12,11,3),(8,11,12,2),(31,13,12,3),(10,14,13,1),(25,11,13,2),(13,17,14,1),(23,13,14,2),(6,11,14,3),(5,19,15,2),(12,16,15,3),(11,15,16,2),(9,13,16,3),(4,20,17,1),(28,7,17,2);
/*!40000 ALTER TABLE `shows` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `showtime`
--

DROP TABLE IF EXISTS `showtime`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
 SET character_set_client = utf8mb4 ;
CREATE TABLE `showtime` (
  `Id` int(11) NOT NULL,
  `StartTime` time NOT NULL,
  `EndTime` time NOT NULL,
  PRIMARY KEY (`Id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `showtime`
--

LOCK TABLES `showtime` WRITE;
/*!40000 ALTER TABLE `showtime` DISABLE KEYS */;
INSERT INTO `showtime` VALUES (1,'11:00:00','14:00:00'),(2,'15:00:00','18:00:00'),(3,'19:00:00','22:00:00');
/*!40000 ALTER TABLE `showtime` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `theater`
--

DROP TABLE IF EXISTS `theater`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
 SET character_set_client = utf8mb4 ;
CREATE TABLE `theater` (
  `Id` bigint(20) NOT NULL,
  `TheaterName` char(50) NOT NULL,
  `City` char(50) NOT NULL,
  `TotalSeats` int(11) NOT NULL,
  `AvailableSeats` int(11) NOT NULL,
  `Rating` float DEFAULT NULL,
  `Price` int(11) NOT NULL,
  PRIMARY KEY (`Id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `theater`
--

LOCK TABLES `theater` WRITE;
/*!40000 ALTER TABLE `theater` DISABLE KEYS */;
INSERT INTO `theater` VALUES (1,'Carnival: Rockline Mall','Bangalore',500,450,4.3,250),(2,'PVR-WhiteFild Road','Bangalore',200,150,4.1,250),(3,'PVR: Vaishnavi Mall, Yeshwanthpur','Bangalore',100,50,3.1,250),(4,'PVR-Marathali','Bangalore',50,25,3.5,250),(5,'INOX, Yalanka','Bangalore',25,10,3.9,150),(6,'INOX, Banjara Hills','Hyderabad',25,10,4.9,150),(7,'PVR, Madahpur','Hyderabad',50,10,3.9,150),(8,'PVR, Punjagutta','Hyderabad',65,10,3.6,150),(9,'Cinepol, Malkajgiri','Hyderabad',75,10,3.2,150),(10,'Cinemax, Thane','Mumbai',25,10,4.9,250),(11,'CinePolis, Andheri','Mumbai',50,10,3.9,250),(12,'Inox, Malad','Mumbai',65,10,3.6,250),(13,'PVR Andheri','Mumbai',75,10,3.2,250),(14,'CinePoll, New Delhi','Delhi',25,10,4.9,255),(15,'Inox, Neharu Palace','Delhi',50,10,3.9,255),(16,'PVR, Noida','Delhi',65,10,3.6,255),(17,'SRS Mall, Faridabad','Delhi',75,10,3.2,255);
/*!40000 ALTER TABLE `theater` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `user`
--

DROP TABLE IF EXISTS `user`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
 SET character_set_client = utf8mb4 ;
CREATE TABLE `user` (
  `MobileNo` bigint(20) NOT NULL,
  `UserPassword` char(20) NOT NULL,
  `UserName` char(50) NOT NULL,
  `EmailId` char(50) NOT NULL,
  `Gender` char(10) NOT NULL,
  `City` char(20) NOT NULL,
  PRIMARY KEY (`MobileNo`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `user`
--

LOCK TABLES `user` WRITE;
/*!40000 ALTER TABLE `user` DISABLE KEYS */;
INSERT INTO `user` VALUES (123456789,'12345','Santosh','santosh796@gmail.com','Male','Hyderabad');
/*!40000 ALTER TABLE `user` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2019-05-11  9:01:58
