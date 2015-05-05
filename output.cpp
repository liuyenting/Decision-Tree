int tree_predict(double *attr) {
	if(attr[1] > 86.5) {
		return 1;
	} else {
		if(attr[3] > 22.5) {
			if(attr[1] > 63.5) {
				return 1;
			} else {
				if(attr[3] > 23.5) {
					if(attr[1] > 47.5) {
						if(attr[1] > 55.5) {
							return -1;
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
			if(attr[1] > 78.5) {
				return -1;
			} else {
				return 1;
			}
		}
	}
}
