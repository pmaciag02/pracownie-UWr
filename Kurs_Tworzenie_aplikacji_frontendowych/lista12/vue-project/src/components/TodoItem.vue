<script setup lang="ts">
const props = defineProps<{
  name: string;
  isCompleted: boolean;
}>();
const emit = defineEmits<{
  (e: "remove"): void;
  (e: "complete"): void;
}>();
const onRemove = () => {
  emit("remove");
};
const onComplete = () => {
  emit("complete");
};
// const condition = false;
</script>

<template>
  <li>
    <span :class="{ done: props.isCompleted }">{{ props.name }}</span>
    <button v-on:click="onComplete">
      {{isCompleted ? 'Mark as Incomplete' : 'Mark as Complete'}}
    </button>
    <button v-on:click="onRemove">Remove</button>
  </li>
</template>


<style>
.done {
  text-decoration: line-through;
}
</style>