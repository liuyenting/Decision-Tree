clear all
close all

filename = 'graph';

delete(strcat(filename, '.train'));
delete(strcat(filename, '.test'));
delete(strcat(filename, '.result'));

resolution = struct('train', 0.5,... 
                    'test', 0.25);
                    
range = struct('x', [-2, 2],...
               'y', [-2, 2],...
               'z', [-2, 2]);
               
generator(strcat(filename, '.train'), @graphic_function, resolution.train, range);
[X Y Z J] = generator(strcat(filename, '.test'), @graphic_function, resolution.test, range);

disp(['Wait for user to paste in the "', strcat(filename, '.result'), '"']); 
waitforbuttonpress

% Read the result
fileID = fopen(strcat(filename, '.result'), 'rt');
input = fscanf(fileID, '%d');
fclose(fileID);

counter = 1;
for x = 1 : length(X)
    for y = 1 : length(Y)
        for z = 1 : length(Z)
            
            %disp('====');
            %disp(input(counter));
            %disp(J(x, y, z));
            %disp('====');
            
            if input(counter) ~= J(x, y, z)
                disp('not match');
                c = 'gx';
                r = 6;
            else
                if J(x, y, z) < 0
                    c = 'r.';
                    r = 4;
                else
                    c = 'bo';
                    r = 8;
                end
            end
            plot3(X(x), Y(y), Z(z), c, 'markersize', r);
            hold on;
            
            counter = counter + 1;
        end
    end
end

grid on

            