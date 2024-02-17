import React, { useState } from 'react';
import { v4 as uuid } from 'uuid';

interface Todo {
  id: string;
  task: string;
  isCompleted: boolean;
}


const TodoList: React.FC = () => {
  const [todos, setTodos] = useState<Todo[]>([]);
  const [task, setTask] = useState('');
  const [counter, setCounter] = useState(0);

  const AddTodo = (event: React.FormEvent<HTMLFormElement>) => {
    event.preventDefault();//????
    if (task.trim()) {
      setTodos(todos=>[...todos, { id: uuid(), task, isCompleted: false }]);
      setTask('');
      setCounter(counter + 1);
    }
  };

  const CompleteTodo = (id: string) => {
    setTodos(
      todos.map((todo) => {
        if (todo.id === id) {
          todo.isCompleted ? setCounter(counter + 1) : setCounter(counter - 1);
          return { id: todo.id, task: todo.task, isCompleted: !todo.isCompleted };
        }
        return todo;
      }),
    );
  };

  const RemoveTodo = (id: string) => {
    let t = todos.filter((todo) => todo.id == id);
    if (!t[0].isCompleted) setCounter(counter - 1);
    setTodos(todos.filter((todo) => todo.id !== id));
  };

  const RemoveAll = () => {
    setTodos([]);
    setCounter(0);
  };


  return (
    <div>
        <p id="sum">last: {counter}</p>
        <button onClick={() => RemoveAll()}>Remove all</button>
      <form onSubmit={AddTodo}>
        <input
          type="text"
          value={task}
          onChange={(event) => setTask(event.target.value)}
        />
        <button type="submit">Add Todo</button>
      </form>
      <ul>
        {todos.map((todo) => (
          <li key={todo.id}>
            <span style={{textDecoration: todo.isCompleted ? 'line-through' : 'none',}}>
              {todo.task}
            </span>
            <button onClick={() => CompleteTodo(todo.id)}>
              {todo.isCompleted ? 'Mark as Incomplete' : 'Mark as Complete'}
            </button>
            <button onClick={() => RemoveTodo(todo.id)}>Remove</button>
          </li>
        ))}
      </ul>
    </div>
  );
};

export default TodoList;
