import { useState } from 'react'
import reactLogo from './assets/react.svg'
import './App.css'

import chad from './assets/imgs/gigachad.jpg'
import foto1 from './assets/imgs/foto1.webp'
import foto2 from './assets/imgs/foto2.webp'
import foto3 from './assets/imgs/foto3.webp'
import foto4 from './assets/imgs/foto5.webp'

function App() {

  return (
    <div className="App">
      <nav class="navbar">
      <div class="container">

          <div>
              <ul class="navbar-nav">
                  <li>
                      <a class="nav-link" href="#home">Home</a>
                  </li>
                  <li>
                      <a class="nav-link" href="#about">O mnie</a>
                  </li>
                  <li>
                      <a class="nav-link" href="#projects">Projekty</a>
                  </li>
                  <li>
                      <a class="nav-link" href="#contact">Kontakt</a>
                  </li>
              </ul>
          </div>
      </div>          
  </nav>


  <header class="header" id="home">
      <div class="container">
          <div class="infos">
              <h2>Hej! Jestem</h2>
              <h6 class="title">Patryk Maciąg</h6>
              <p>najlepszy frontendowiedz po tej stronie Pontaru</p>
          </div>     
          <div class="img-holder">
              <img src={chad}/>
          </div>         
      </div>

      <div class="widget">
          <div class="widget-item">
              <h2>0</h2>
              <p>Zadowolonych klientów</p>
          </div>
      </div>
  </header>

  <section id="about" class="section">
      <div class="container">
          <div class="row text-center text-md-left">
              <div>
                  <h6 class="title">Patryk Maciąg</h6>
                  <p>Lorem ipsum dolor sit amet consectetur adipisicing elit. Adipisci nesciunt expedita earum dicta nulla eaque eveniet architecto vero commodi porro tempora nobis explicabo quo ipsam sunt, cumque dolore. Sed, esse.</p>                  
              </div>
          </div>
      </div>
  </section>


  <section class="section">
      <div class="container text-center">
          <h2>Skille</h2>

          <div class="text-left">
              <div>
                  <h3>Gra na gitarze</h3>
                  <div class="progress">
                      <div class="progress-bar bg-primary" role="progressbar" style="width: 90%;" aria-valuenow="25" aria-valuemin="0" aria-valuemax="100"><span>90%</span></div>
                  </div>
              </div>
              <div>
                  <h3>Tworzenie aplikacji</h3>
                  <div class="progress">
                      <div class="progress-bar bg-primary" role="progressbar" style="width: 30%;" aria-valuenow="25" aria-valuemin="0" aria-valuemax="100"><span>30%</span></div>
                  </div>
              </div>
          </div>  
      </div>
  </section>






  
  <section id="projects" class="section">
      <div class="container text-center">
          <h2>Projekty</h2>

          <div class="row">
              <div>
                  <div class="img-wrapper">
                      <img src={foto1}/>
                      <div class="overlay">
                          <div class="overlay-infos">
                              <a href="https://github.com">Projekt 1</a>
                          </div>  
                      </div>
                  </div>
                  <div class="img-wrapper">
                  <img src={foto2}/>
                      <div class="overlay">
                          <div class="overlay-infos">
                              <a href="https://github.com">Projekt 2</a>
                          </div>  
                      </div>
                  </div>                 
              </div>
              <div>
                  <div class="img-wrapper">
                  <img src={foto3}/>
                      <div class="overlay">
                          <div class="overlay-infos">
                              <a href="https://github.com">Projekt 3</a>
                          </div>  
                      </div>
                  </div>
                  <div class="img-wrapper">
                  <img src={foto4}/>
                      <div class="overlay">
                          <div class="overlay-infos">
                              <a href="https://github.com">Projekt 4</a>
                          </div>  
                      </div>
                  </div>                 
              </div>
          </div>

      </div>
  </section>


  

 
  <section id="contact" class="position-relative section">
      <div class="container text-center">

          <div class="contact text-left">
              <div class="form">
                  <h6 class="section-title mb-4">Kontakt</h6>
                  <form>
                      <div class="form-group">
                          <input type="email" class="form-control" id="exampleInputEmail1" aria-describedby="emailHelp" placeholder="email" required/>
                      </div>
                      <div class="form-group">
                          <textarea name="contact-message" id="" cols="30" rows="5" class="form-control" placeholder="treść"></textarea>
                      </div>
                      <button type="submit" class="btn btn-primary btn-block rounded">Wyślij</button>
                  </form>
              </div>
              <div class="contact-infos">
                      <i class="ti-mobile"></i>
                      <div>
                          <h5>Numer kontaktowy</h5>
                          <p>123 456 789</p>
                      </div>
                      <i class="ti-email"></i>
                      <div class="mb-0">
                          <h5>Email</h5>
                          <p>6969pussydestroyer6969@gmail.com</p>
                      </div>
              </div>                  
          </div>
      </div>  
  </section>

    </div>
  )
}

export default App
