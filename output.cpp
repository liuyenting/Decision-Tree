int tree_predict(double *attr) {
	if(attr[ 1 ] > -2147483648) {
		return 1;
	} else {
		if(attr[ 3 ] > -2147483648) {
			if(attr[ 1 ] > -2147483648) {
				return 1;
			} else {
				if(attr[ 3 ] > -2147483648) {
					if(attr[ 1 ] > -2147483648) {
						if(attr[ 1 ] > -2147483648) {
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
			if(attr[ 1 ] > -2147483648) {
				return -1;
			} else {
				return 1;
			}
		}
	}
}
