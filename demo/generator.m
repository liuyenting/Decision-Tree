function [X Y Z J] = generator(filename, judge, resolution, range)

    X = linspace(range.x(1), range.x(2), (range.x(2)-range.x(1))/resolution);
    Y = linspace(range.y(1), range.y(2), (range.y(2)-range.y(1))/resolution);
    Z = linspace(range.z(1), range.z(2), (range.z(2)-range.z(1))/resolution);
        
    % Preallocated the space for output matrix
    J = zeros(length(X), length(Y), length(Z));
    
    for x = 1 : length(X)
        for y = 1 : length(Y)
            for z = 1 : length(Z)
                J(x, y, z) = judge(X(x), Y(y), Z(z));
            end
        end
    end
    
    % Output the matrix into LIBSVM format
    fileID = fopen(filename, 'w');
    for x = 1 : length(X)
        for y = 1 : length(Y)
            for z = 1 : length(Z)
                tmp = J(x, y, z);
                fprintf(fileID, '%d 1:%.6f 2:%.6f 3:%.6f\n',...
                                 J(x, y, z), X(x), Y(y), Z(z));
                J(x, y, z) = judge(X(x), Y(y), Z(z));
            end
        end
    end
    fclose(fileID);
    
end
