int tree_predict(double *attr) {
  if(attr[1] > 86.5) {
    return 1;
  } else {
    if(attr[1] > 45) {
      if(attr[3] > 30) {
        return 1;
      } else {
        if(attr[1] > 49.5) {
          if(attr[1] > 55.5) {
            if(attr[1] > 66.5) {
              if(attr[1] > 78.5) {
                return -1;
              } else {
                return 1;
              }
            } else {
              return -1;
            }
          } else {
            return -1;
          }
        } else {
          return -1;
        }
      }
    } else {
      return -1;
    }
  }
}
