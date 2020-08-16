/*
 * @Author: youngjam
 * @Date: 2020-01-14 16:20:53
 * @LastEditTime: 2020-04-23 13:32:25
 * @Description: 测试 h 文件
 * @logs: 
    *2020.4.22:新增stack.h文件的测试代码
 */
// #include<time.h>
// #include<stdlib.h>
// #include "datatype.h"
// #include "singlelinklist.h"
// #include "binarytree.h"
#include"stack.h"

int main(void)
{
    /*
     *测试datatype.h文件
    */
    /*
    data_type e1, e2;
    get_data(&e1);
    get_data(&e2);
    if (compare_element(e1, e2))
        swap_element(&e1, &e2);
    print_data(e1);
    print_data(e2);
    return 0;
    */
   /*
    * 测试singlelinklist.c文件
   */
  /*
  link_list head = NULL;
  printf("测试链表初始化函数：\n");
  init_list(&head);
  printf("address = %p\n", head);
  printf("测试增加节点函数：\n");
  for (int i = 0; i < 6; i++) {
      add_node(head);
  }
  printf("测试链表打印函数：\n");
  print_list(head);
  printf("测试链表插入函数:\n");
  for (int i = 0; i < 3; i++) {
      data_type data = 0;
      get_data(&data);
      insert_node(&head, data);
      print_list(head);
  }
  printf("测试节点删除函数：\n");
  for (int i = 0; i < 3; i++) {
      data_type data = 0;
      get_data(&data);
      delete_node(&head, data);
      print_list(head);
  }
  printf("测试链表置空函数：\n");
  empty_list(&head);
  printf("address = %p\n", head);
  */
 /******************/
 /* 测试二叉树 */
 /*
    srand((unsigned int)time(NULL));
    tree root = NULL;
    printf("test init_tree():\n");
    root = init_tree(root);
    printf("root = %p\n", root);
    printf("test build_tree():\n");
    for (int i = 0; i < 12; i++) {
        printf("input = %d\n", rand() % 20);
        build_tree(root);
    }
    printf("==== preorder ====\n");
    preorder_traversal(root);
    printf("==== inorder ====\n");
    inorder_traversal(root);
    printf("==== postorder ====\n");
    postorder_traversal(root);
    printf("test delete_tree():\n");
    root = delete_tree(root);
    printf("address = %p\n", root);
*/
/******* 测试 stack.h *******/
    stack *s = nullptr;
    s = init_stack(s);
    printf("%p\n", s);
    char flag = 'c';
    while (flag != 'q') {
        printf("\nflag = 1 => push; flag = 0 => pull; flag = q => exit!\n");
        // while ((flag = getchar()) != EOF && flag != '\n');
        setbuf(stdin, NULL);
        scanf("%c", &flag);
        if (flag == '1') {
            // char element = '\0';
            // get_from_scanf(&element);
            push_stack(s);
        }
        else if (flag == '0')
            pull_stack(s);
    }
    while (s->size >0 ){
        pull_stack(s);
    }
    free_stack(s);
    return 0;
}