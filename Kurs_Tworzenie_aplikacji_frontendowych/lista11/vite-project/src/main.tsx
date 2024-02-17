import React from 'react'
import ReactDOM from 'react-dom/client'
import App from './App'
import './index.css'
import TodoList from './TodoList';

ReactDOM.createRoot(document.getElementById('root') as HTMLElement).render(
  <React.StrictMode>
    {/* <App /> */}
    <TodoList />
  </React.StrictMode>,
)
