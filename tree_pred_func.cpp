int tree_predict(double *attr) {
  if(attr[1] > 0.284805) {
    if(attr[1] > 0.558995) {
      if(attr[1] > 0.64366) {
        if(attr[2] > 0.64687) {
          return 1;
        } else {
          return -1;
        }
      } else {
        return 1;
      }
    } else {
      return -1;
    }
  } else {
    return 1;
  }
}
