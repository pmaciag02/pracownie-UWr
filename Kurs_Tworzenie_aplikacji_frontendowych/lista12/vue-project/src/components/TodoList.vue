<script setup lang="ts">
import TodoItem from "./TodoItem.vue";
import { ref } from "vue";
import { v4 as uuid } from 'uuid';

const tasks = ref([
  { id: uuid(), name: "task1", isCompleted: false},
  { id: uuid(), name: "task2", isCompleted: false},
  { id: uuid(), name: "task3", isCompleted: false},
]);


let counter = 3;
// let text = '';

const removeItem = (id: string) => {
  let t = tasks.value.filter((task) => task.id == id);
  if (!t[0].isCompleted) counter -= 1;
  tasks.value = tasks.value.filter((task) => task.id !== id);
};


const CompleteTodo = (id: string) => {
    tasks.value = tasks.value.map((todo) => {
      if (todo.id === id) {
        todo.isCompleted ? counter += 1 : counter -= 1;
        return { id: todo.id, name: todo.name, isCompleted: !todo.isCompleted };
      }
      return todo;
    });
};


const addTodo = () => {
  tasks.value.push({ id: uuid(), name: newTodo, isCompleted: false });
  newTodo = '';
  counter += 1;
};

const RemoveAll = () => {
    tasks.value = [];
    counter = 0;
  };

let newTodo = '';

</script>

<template>
  <ul>
    <p>last: {{counter}}</p>
    <button @click="RemoveAll">Remove all</button>
    <form @submit.prevent="addTodo">
      <input v-model="newTodo">
      <button>Add Todo</button>    
    </form>
    <TodoItem
      v-for="task in tasks"
      v-bind:key="task.id"
      v-bind:name="task.name"
      v-bind:is-completed="task.isCompleted"
      v-on:remove="removeItem(task.id)"
      v-on:complete="CompleteTodo(task.id)"
    />
  </ul>
</template>