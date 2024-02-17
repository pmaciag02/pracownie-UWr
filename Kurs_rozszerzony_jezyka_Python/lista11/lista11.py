from sqlalchemy.ext.declarative import declarative_base
from sqlalchemy import Column, Integer, String, ForeignKey
from sqlalchemy import create_engine
from sqlalchemy.orm import sessionmaker, relationship
import sys

Base = declarative_base()

class Movie(Base):
    __tablename__ = 'Movie'

    id = Column(Integer, primary_key=True)
    title = Column(String)
    year = Column(Integer)
    director_id = Column(Integer, ForeignKey('directors.id'))
    operator_id = Column(Integer, ForeignKey('operators.id'))
    producer_id = Column(Integer, ForeignKey('producers.id'))

    def __repr__(self):
        return "<Movie(title: '%s', year: '%d', director: '%s', operator: '%s', producer: '%s')>" % (self.title, self.year, session.query(Director).filter_by(id=self.director_id).one(), session.query(Operator).filter_by(id=self.operator_id).one(), session.query(Producer).filter_by(id=self.producer_id).one())

class Director(Base):
    __tablename__ = 'directors'

    id = Column(Integer, primary_key=True)
    name = Column(String)
    movies = relationship("Movie")

    def __repr__(self):
        return "<Director(name: '%s')>" % (self.name)


class Operator(Base):
    __tablename__ = 'operators'

    id = Column(Integer, primary_key=True)
    name = Column(String)
    movies = relationship("Movie")

    def __repr__(self):
        return "<Operator(name: '%s')>" % (self.name)


class Producer(Base):
    __tablename__ = 'producers'

    id = Column(Integer, primary_key=True)
    name = Column(String)
    movies = relationship("Movie")

    def __repr__(self):
        return "<Producer(name: '%s')>" % (self.name)

def add_movie():
    engine = create_engine('sqlite:///movies.db')
    Session = sessionmaker(bind=engine)
    session = Session()

    title = sys.argv[3]
    year = sys.argv[4]
    director = sys.argv[5]
    operator = sys.argv[6]
    producer = sys.argv[7]

    try:
        base_director = session.query(Director).filter_by(name=director).one()
    except:
        print("Brak reżysera w bazie.")
        base_director = Director(name=director)
        session.add(base_director)
        print("Dodano reżysera do bazy.")
    try:
        base_operator = session.query(Producer).filter_by(name=producer).one()
    except:
        print("Brak operatora w bazie.")
        base_operator = Operator(name=operator)
        session.add(base_operator)
        print("Dodano operatora do bazy.")
    try:
        base_producer = session.query(Producer).filter_by(name=producer).one()
    except:
        print("Brak producenta w bazie.")
        base_producer = Producer(name=producer)
        session.add(base_producer)
        print("Dodano producenta do bazy.")

    new_movie = Movie(title=title, year=year)
    base_director.movies.append(new_movie)
    base_operator.movies.append(new_movie)
    base_producer.movies.append(new_movie)
    session.add(new_movie)
    session.commit()


def add_director():
    engine = create_engine('sqlite:///movies.db')
    Session = sessionmaker(bind=engine)
    session = Session()
    name = sys.argv[3]

    new_director = Director(name=name)
    session.add(new_director)
    session.commit()


def add_operator():
    engine = create_engine('sqlite:///movies.db')
    Session = sessionmaker(bind=engine)
    session = Session()
    name = sys.argv[3]

    new_operator = Operator(name=name)
    session.add(new_operator)
    session.commit()


def add_producer():
    engine = create_engine('sqlite:///movies.db')
    Session = sessionmaker(bind=engine)
    session = Session()
    name = sys.argv[3]

    new_producer = Producer(name=name)
    session.add(new_producer)
    session.commit()


if len(sys.argv) == 2:
    if sys.argv[1] == '--start':
        engine = create_engine('sqlite:///movies.db')
        Base.metadata.create_all(engine)

    elif sys.argv[1] == '--show_movies':
        engine = create_engine('sqlite:///movies.db')
        Session = sessionmaker(bind=engine)
        session = Session()
        for movie in session.query(Movie).order_by(Movie.id):
            print(movie)

    elif sys.argv[1] == '--show_directors':
        engine = create_engine('sqlite:///movies.db')
        Session = sessionmaker(bind=engine)
        session = Session()
        for director in session.query(Director).order_by(Director.id):
            print(director)

    elif sys.argv[1] == '--show_operators':
        engine = create_engine('sqlite:///movies.db')
        Session = sessionmaker(bind=engine)
        session = Session()
        for operator in session.query(Operator).order_by(Operator.id):
            print(operator)

    elif sys.argv[1] == '--show_producers':
        engine = create_engine('sqlite:///movies.db')
        Session = sessionmaker(bind=engine)
        session = Session()
        for producer in session.query(Producer).order_by(Producer.id):
            print(producer)

    elif sys.argv[1] == '--help':
        print("--start - utwórz plik bazy danych")
        print("--add movie <tytół> <rok powstania> <reżyser> <operator> <producent> - dodaj film")
        #przykład: python3 lista11.py --add movie Film#1 2021 Janusz Kamil WB
        print("--add director <reżyser> - dodaj reżysera")
        print("--add producer <producent> - dodaj producenta")
        print("--show_movies - pokaż tablę filmów")
        print("--show_directors - pokaż tablę reżyserów")
        print("--show_producers - pokaż tablę producentów")

elif (len(sys.argv) == 8 or len(sys.argv) == 4) and sys.argv[1] == '--add':
    if sys.argv[2] == 'movie':
        add_movie()
    if sys.argv[2] == 'director':
        add_director()
    if sys.argv[2] == 'operator':
        add_operator()
    if sys.argv[2] == 'producer':
        add_producer()

else:
    print("Błąd wejścia. Podaj właściwe argumenty podczas wywołania programu.")