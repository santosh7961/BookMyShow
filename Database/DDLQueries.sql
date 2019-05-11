/*create database BookMyShow;*/
create table User( MobileNo BIGINT  primary key,
					UserPassword char(20) not null,
					UserName char(50) not null,
                    EmailId char(50) not null,
                    Gender char(10) not null,
                    City char(20) not null);
					
create table Movie(Id bigint primary key,
					MovieName char(50) not null,
                    Languages text(500) not null,
                    MovieType char(20),
                    ReleaseDate date not null,
                    Rating int,
                    StarCasts text(300));
alter table movie modify Rating float;

create table Theater(Id bigint primary key,
					TheaterName char(50) not null,
					City char(50) not null,
                    TotalSeats int not null,
                    AvailableSeats int not null,
                    Rating float);
alter table Theater add column Price int not null;					
					
create table ShowTime(Id int primary key,
					StartTime time not null,
                    EndTime time not null);					

create table Shows(Id int primary key,
					MovieId bigint not null,
                    TheaterId bigint not null,
					ShowsTime int not null,
                    FOREIGN KEY (MovieId) REFERENCES Movie(Id),
                    FOREIGN KEY (TheaterId) REFERENCES Theater(Id),
                    FOREIGN KEY (ShowsTime) REFERENCES ShowTime(Id),
                    CONSTRAINT duplicate_all unique(TheaterId,ShowsTime,MovieId),
                    /*avoid Duplcate entires for the same movie, same theater, same time*/
                    CONSTRAINT duplicate_two unique(TheaterId,ShowsTime)
                    /*Same theater at the same time cat't play 2 movies*/);

create table Booking(BookingId int not null AUTO_INCREMENT,
					 UserId bigint not null,
                     ShowId int not null,
                     NoOfSeatsBooked int not null,
                     AmountPaid int not null,
                     foreign key (UserId) references User(MobileNo),
                     FOREIGN KEY (ShowId) REFERENCES shows(Id),
                     primary key(BookingId)
                     );					
 
insert into User values(123456789,'12345','Santosh', 'santosh796@gmail.com','Male','Hyderabad');

 
insert into movie values(1, 'Avangers', 'English', 'Action', '2019-04-26', 4.3,'Chris Evans, Robert Downey');
insert into movie values(2, 'How to train your dragon', 'English', 'Adventure', '2019-04-21', 4.3,'Jay Baruchel, Gerand Butler');
insert into movie values(3, 'Kalank', 'Hindi', 'Drama', '2019-04-17', 2.8,'Varun Dhawan, Alia Bhatt');
insert into movie values(4, 'Jersey', 'Telugu', 'Drama', '2019-04-19', 3.8,'Nani, Sardha');
insert into movie values(5, 'Kavaludaari', 'Kannada', 'Crime', '2019-04-12', 3.2,'Rishi, Anant Nag');
insert into movie values(6, 'Chhota Bheem', 'English', 'Action', '2019-05-10', 4.3,'Rajiv Chilaka, Robert Downey');
insert into movie values(7, 'The Curse Of The Weeping Woman', 'English', 'Horror', '2019-04-19', 2.5,'Linda, Patricia');
insert into movie values(8, 'Shazam!', 'English', 'Action', '2019-04-5', 4.3,'Mark	Strong, Zachrya Levi');
insert into movie values(9, 'Dumbo', 'English', 'Action', '2019-03-29', 3.5,'Eva, Green');
insert into movie values(10, 'Student of the Year 2', 'Hindi', 'Drama', '2019-05-10', 5.3,'Tiger Shroff, Ananya Pandey');
insert into movie values(11, 'Godzilla 2', 'English', 'Adventure', '2019-05-31', 3.3,'Vera Farmiga, Kyle Chandler');
insert into movie values(12, 'X-Men', 'English', 'Action', '2019-08-26', 1.3,'Evans,  Downey');
insert into movie values(13, 'Bharat', 'Hindi', 'Action', '2019-07-26', 2.3,'Salman Khan');
insert into movie values(14, 'Kabir Singh', 'Hindi', 'Action', '2019-06-26', 3.3,'John Abraham');
insert into movie values(15, 'Spider-Man Far from home', 'English', 'Action', '2019-05-26', 4.6,'Chris , Robert');
insert into movie values(16, 'The Lion King', 'English', 'Action', '2019-08-23', 4.5,'Vere munda');
insert into movie values(17, 'Super 30', 'Hindi', 'Action', '2019-05-16', 4.4,'Hritik Roshan');
insert into movie values(18, 'Shahoo', 'Telugu', 'Action', '2019-7-09', 4.2,'Anmay Mishra');
insert into movie values(19, 'Rambo', 'Hidni', 'Action', '2019-04-21', 4.1,'Tiger Sharoff');
insert into movie values(20, 'Street Dancer', 'Hindi', 'Action', '2019-06-26', 3.3,'Varun Dhawan');
 

update theater set Price=200 where Id between 14 and 17;
insert into Theater values(1, 'Carnival: Rockline Mall', 'Bangalore', 500, 450, 4.3);
insert into Theater values(2, 'PVR-WhiteFild Road', 'Bangalore', 200, 150, 4.1);
insert into Theater values(3, 'PVR: Vaishnavi Mall, Yeshwanthpur', 'Bangalore', 100, 50, 3.1);
insert into Theater values(4, 'PVR-Marathali', 'Bangalore', 50, 25, 3.5);
insert into Theater values(5, 'INOX, Yalanka', 'Bangalore', 25, 10, 3.9);

insert into Theater values(6, 'INOX, Banjara Hills', 'Hyderabad', 25, 10, 4.9);
insert into Theater values(7, 'PVR, Madahpur', 'Hyderabad', 50, 10, 3.9);
insert into Theater values(8, 'PVR, Punjagutta', 'Hyderabad', 65, 10, 3.6);
insert into Theater values(9, 'Cinepol, Malkajgiri', 'Hyderabad', 75, 10, 3.2);

insert into Theater values(10, 'Cinemax, Thane', 'Mumbai', 25, 10, 4.9);
insert into Theater values(11, 'CinePolis, Andheri', 'Mumbai', 50, 10, 3.9);
insert into Theater values(12, 'Inox, Malad', 'Mumbai', 65, 10, 3.6);
insert into Theater values(13, 'PVR Andheri', 'Mumbai', 75, 10, 3.2);

insert into Theater values(14, 'CinePoll, New Delhi', 'Delhi', 25, 10, 4.9);
insert into Theater values(15, 'Inox, Neharu Palace', 'Delhi', 50, 10, 3.9);
insert into Theater values(16, 'PVR, Noida', 'Delhi', 65, 10, 3.6);
insert into Theater values(17, 'SRS Mall, Faridabad', 'Delhi', 75, 10, 3.2);


insert into ShowTime values(1, '11:00:00', '14:00:00');
insert into ShowTime values(2, '15:00:00', '18:00:00');
insert into ShowTime values(3, '19:00:00', '22:00:00');
 

insert into Shows values(1, 1, 1, 1);
insert into Shows values(2, 2, 1, 2);
insert into Shows values(3, 3, 1, 3); 
insert into Shows values(4, 20, 17, 1);
insert into Shows values(5, 19, 15, 2);/*Same move, same theater differet time*/
insert into Shows values(6, 11, 14, 3);
insert into Shows values(7, 12, 11, 1);
insert into Shows values(8, 11, 12, 2);/*Same move, same theater differet time*/
insert into Shows values(9, 13, 16, 3);
insert into Shows values(10, 14, 13, 1);
insert into Shows values(11, 15, 16, 2);/*Same move, same theater differet time*/
insert into Shows values(12, 16, 15, 3);
insert into Shows values(13, 17, 14, 1);
insert into Shows values(14, 18, 11, 2);/*Same move, same theater differet time*/
insert into Shows values(15, 19, 9, 3);
insert into Shows values(16, 20, 8, 1);
insert into Shows values(17, 19, 7, 2);/*Same move, same theater differet time*/
insert into Shows values(18, 18, 6, 3);
insert into Shows values(19, 17, 5, 1);
insert into Shows values(20, 16, 4, 2);/*Same move, same theater differet time*/
insert into Shows values(21, 15, 3, 3);
insert into Shows values(22, 14, 2, 1);
insert into Shows values(23, 13, 14, 2);/*Same move, same theater differet time*/
insert into Shows values(24, 12, 11, 3);
insert into Shows values(25, 11, 13, 2);
insert into Shows values(26, 10, 9, 2);/*Same move, same theater differet time*/
insert into Shows values(27, 9, 8, 3);
insert into Shows values(28, 7, 17, 2);/*Same move, same theater differet time*/
insert into Shows values(29, 6, 7, 3);
insert into Shows values(30, 5, 3, 1);
insert into Shows values(31, 13, 12, 3);
insert into Shows values(32, 2, 4, 3);
insert into Shows values(33, 12, 5, 2);/*Same move, same theater differet time*/
insert into Shows values(34, 11, 5, 3);
insert into Shows values(35, 10,  6, 1);
insert into Shows values(36, 9, 8, 2);/*Same move, same theater differet time*/
insert into Shows values(37, 8, 10, 3); 
insert into Shows values(38, 5, 6, 2); 

                     
insert into Booking (UserId,ShowId,NoOfSeatsBooked,AmountPaid)values(123456789,1,2,500);

update theater inner join shows on shows.theaterId = theater.Id
set AvailableSeats=10-3 where shows.Id=1;			
 
select booking.BookingId, movie.MovieName,theater.TheaterName,ShowTime.StartTime,
booking.NoOfSeatsBooked,booking.AmountPaid from Booking 
join shows on shows.id= booking.ShowId
join theater on theater.Id = shows.theaterId
join movie on movie.Id=shows.MovieId
join ShowTime on movie.Id=shows.MovieId
join user on shows.userId = user.MobileNo
where user.Id =123456789

join ShowTime on ShowTime.Id = show.ShowsTime;
 
 
 /*To get the movie details based on city*/
select shows.Id,movie.MovieName,movie.Languages,movie.MovieType,movie.ReleaseDate,
movie.Rating, movie.StarCasts,Showtime.starttime,theater.TheaterName, 
theater.AvailableSeats from Movie 
inner join Shows  on movie.Id = shows.MovieId   
inner join Showtime on showtime.Id = shows.showstime   
inner join Theater on theater.Id = shows.TheaterId 
where theater.City='Delhi' order by shows.id; 

 /*To get the Theaters  detail based in city */  
select shows.Id, theater.TheaterName, movie.MovieName, movie.Languages, movie.MovieType,
movie.ReleaseDate, movie.Rating, movie.StarCasts, Showtime.starttime, theater.AvailableSeats 
from Movie 
inner join Shows  on movie.Id = shows.MovieId   
inner join Showtime on showtime.Id = shows.showstime   
inner join Theater on theater.Id = shows.TheaterId 
where theater.City='Delhi' order by shows.id , theater.TheaterName ;     
     
  
select distinct(Theater.TheaterName) from Theater 
inner join Shows  on theater.Id = shows.TheaterId    
where theater.City='Delhi';  

select theater.AvailableSeats,theater.TheaterName  from theater 
inner join Shows on shows.theaterId = theater.Id
where shows.id=1