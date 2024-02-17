from sqlalchemy.ext.declarative import declarative_base
from sqlalchemy import Column, Integer, String, ForeignKey
from sqlalchemy import create_engine
from sqlalchemy.orm import sessionmaker, relationship
import sys

from flask import Flask, request, jsonify, render_template
app = Flask(__name__)

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

def add_movie(t, y, d, o, p):
    engine = create_engine('sqlite:///movies.db')
    Session = sessionmaker(bind=engine)
    session = Session()

    # title = sys.argv[3]
    # year = sys.argv[4]
    # director = sys.argv[5]
    # operator = sys.argv[6]
    # producer = sys.argv[7]
    title = t
    year = y
    director = d
    operator = o
    producer = p

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


def add_director(n):
    engine = create_engine('sqlite:///movies.db')
    Session = sessionmaker(bind=engine)
    session = Session()
    # name = sys.argv[3]
    name = n

    new_director = Director(name=name)
    session.add(new_director)
    session.commit()


def add_operator(n):
    engine = create_engine('sqlite:///movies.db')
    Session = sessionmaker(bind=engine)
    session = Session()
    # name = sys.argv[3]
    name = n

    new_operator = Operator(name=name)
    session.add(new_operator)
    session.commit()


def add_producer(n):
    engine = create_engine('sqlite:///movies.db')
    Session = sessionmaker(bind=engine)
    session = Session()
    # name = sys.argv[3]
    name = n

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
        print("serwer pod adresem: http://localhost:5000/")
        print("--start - utwórz plik bazy danych")
        print("--add movie <tytół> <rok powstania> <reżyser> <operator> <producent> - dodaj film")
        #przykład: python3 lista12.py --add movie Film#1 2021 Janusz Kamil WB
        print("--add director <reżyser> - dodaj reżysera")
        print("--add producer <producent> - dodaj producenta")
        print("--show_movies - pokaż tablę filmów")
        print("--show_directors - pokaż tablę reżyserów")
        print("--show_producers - pokaż tablę producentów")

elif (len(sys.argv) == 8 or len(sys.argv) == 4) and sys.argv[1] == '--add':
    if sys.argv[2] == 'movie':
        add_movie(sys.argv[3], sys.argv[4], sys.argv[5], sys.argv[6], sys.argv[7])
    if sys.argv[2] == 'director':
        add_director(sys.argv[3])
    if sys.argv[2] == 'operator':
        add_operator(sys.argv[3])
    if sys.argv[2] == 'producer':
        add_producer(sys.argv[3])

else:
    print("Błąd wejścia. Podaj właściwe argumenty podczas wywołania programu.")



@app.route("/")
def main():
    return render_template('main.html')

@app.route('/directors')
def show_directors():
    engine = create_engine('sqlite:///movies.db')
    Session = sessionmaker(bind=engine)
    session = Session()
    return render_template('showall.html', nazwa = "Reżyserowie", obiekty = session.query(Director).order_by(Director.id))


@app.route('/directors/<int:ide>', methods=['GET'])
def get_director(ide):
    engine = create_engine('sqlite:///movies.db')
    Session = sessionmaker(bind=engine)
    session = Session()
    return render_template('showone.html', nazwa = "Reżyser", obiekt = session.query(Director).filter_by(id=ide).one())


@app.route('/directors/create', methods=('GET', 'POST'))
def create_director():
    if request.method == 'POST':
        name = request.form['nazwa']
        add_director(name)
    return render_template('create-team.html', rodzaj = "reżysera", placeh = "Jan")



@app.route('/operators')
def show_operators():
    engine = create_engine('sqlite:///movies.db')
    Session = sessionmaker(bind=engine)
    session = Session()
    return render_template('showall.html', nazwa = "Operatorzy", obiekty = session.query(Operator).order_by(Operator.id))


@app.route('/operators/<int:ide>', methods=['GET'])
def get_operator(ide):
    engine = create_engine('sqlite:///movies.db')
    Session = sessionmaker(bind=engine)
    session = Session()
    return render_template('showone.html', nazwa = "Operator", obiekt = session.query(Operator).filter_by(id=ide).one())


@app.route('/operators/create', methods=('GET', 'POST'))
def create_operator():
    if request.method == 'POST':
        name = request.form['nazwa']
        add_operator(name)
    return render_template('create-team.html', rodzaj = "operatora", placeh = "Jan")


@app.route('/producers')
def show_producers():
    engine = create_engine('sqlite:///movies.db')
    Session = sessionmaker(bind=engine)
    session = Session()
    return render_template('showall.html', nazwa = "Producenci", obiekty = session.query(Producer).order_by(Producer.id))


@app.route('/producers/<int:ide>', methods=['GET'])
def get_producer(ide):
    engine = create_engine('sqlite:///movies.db')
    Session = sessionmaker(bind=engine)
    session = Session()
    return render_template('showone.html', nazwa = "Producent", obiekt = session.query(Producer).filter_by(id=ide).one())


@app.route('/producers/create', methods=('GET', 'POST'))
def create_producer():
    if request.method == 'POST':
        name = request.form['nazwa']
        add_producer(name)
    return render_template('create-team.html', rodzaj = "producenta", placeh = "WB")



@app.route('/movies')
def show_movies():
    engine = create_engine('sqlite:///movies.db')
    Session = sessionmaker(bind=engine)
    session = Session()
    return render_template('showallmovies.html', nazwa = "Filmy", obiekty = session.query(Movie).order_by(Movie.id))


@app.route('/movies/<int:ide>', methods=['GET'])
def get_movie(ide):
    engine = create_engine('sqlite:///movies.db')
    Session = sessionmaker(bind=engine)
    session = Session()
    film = session.query(Movie).filter_by(id=ide).one()
    # return render_template('showonemovie.html', nazwa = "Film", obiekt = session.query(Movie).filter_by(id=ide).one())
    return render_template('showonemovie.html', nazwa = "Film", obiekt = film, rezyser = session.query(Director).filter_by(id=film.director_id).one(), operator = session.query(Operator).filter_by(id=film.operator_id).one(), producent = session.query(Producer).filter_by(id=film.producer_id).one())


@app.route('/movies/create', methods=('GET', 'POST'))
def create_movie():
    if request.method == 'POST':
        t = request.form['nazwa']
        y = request.form['rok']
        d = request.form['rezyser']
        o = request.form['operator']
        p = request.form['producent']
        add_movie(t, y, d, o, p)

        # return redirect(url_for('main'))
    return render_template('create-movie.html')






if __name__ == '__main__':
    app.run(debug=False, host='0.0.0.0', port=5000)