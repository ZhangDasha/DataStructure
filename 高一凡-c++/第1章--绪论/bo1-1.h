// bo1-1.h抽象数据类型Triplet和ElmeType（由 c1-1.h定义）的基本操作
Status InitTriplet(Triplet &T, ElemType v1, ElemType v2, ElemType v3){
  // 操作结果： 构造三元组T，依次置T的三个元素的初值为v1，v2，v3
  T = (ElemType *)malloc(3 * sizeof(ElemType)); //分配三个元素的存储空间
  if(!T)
    exit(OVERFLOW);  //分配失败则退出
  T[0] = v1, T[1] = v2, T[2] = v3;
  return OK;
}

Status DestroyTriplet(Triplet &T){
  // 操作结果：三元组T被销毁
  free(T);  //释放T所指的三元组存储空间
  T = NULL;
  return OK;
}

Status Get(Triplet T, int i, ElemType &e){
  // 初始条件： 三元组T已存在，1<=i<=3.操作结果：用e返回T的第i元的值。
  if(i<1 || i>3)  //i不在三元组的范围之内
    return ERROR;
  e = T[i-1];   //将三元组T的第i个元素的值赋值给e
  return OK;
}

Status Put(Triplet T, int i, ElemType e){
  // 初始条件：三元组T已存在，1<=i<=3.操作结果：改变T的第i元值为e。
  if(i<1 || i>3)  //i不在三元组的范围之内
    return ERROR;
  T[i-1] = e;  //将e的值赋值给三元组T的第i个元素
  return OK;
}

Status IsAscending(Triplet T){
  // 初始条件：三元组T已存在，操作结果：如果T的三个元素按升序排列，则返回1；否则返回0
  return(T[0] >= T[1] && T[1] >= T[2]); //只在T[0]不大于T[1]且不大于T[2]时返回真
}

Status IsDescending(Triplet T){
  // 初始条件：三元组T已存在，操作结果：如果T的三个元素按降序排列，则返回1；否则返回0
  return(T[0] >= T[1] && T[1] >= T[2]);
}

Status Max(Triplet T, ElemType &e){
  // 初始条件：三元组T已存在，操作结果：用e返回指向T的最大元素值
  e = (T[0] >= T[1]) ? (T[0] >= T[2] ? T[0]:T[2]) : (T[1] >= T[2] ? T[1]:T[2]);
  return OK;
}

Status Min(Triplet T, ElemType &e){
  // 初始条件：三元组T已存在，操作结果: 用e返回指向T的最小元素的值
  e = (T[0] <= T[1]) ? (T[0] <= T[2] ? T[0]:T[2]) : (T[1] <= T[2] ? T[1]:T[2]);
  return OK;
}




