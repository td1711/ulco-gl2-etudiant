import System.IO

add3 :: Int -> Int 
add3 = (+3)

mul2 :: Int -> Int
mul2 = (*2)

mycompute :: Int -> IO Int
mycompute v0 = do
    putStrLn ("add3 " ++ show v0)
    let v1 = add3 v0
    putStrLn ("mul2 " ++ show v1)
    let v2 = mul2 v1
    return v2

mycomputeFile :: Int -> IO Int
mycomputeFile v0 = do
    message <- openFile "message.txt" WriteMode
    hPutStrLn message ("add3 " ++ show v0)
    let v1 = add3 v0
    hPutStrLn message ("mul2 " ++ show v1)
    let v2 = mul2 v1
    hClose message
    return v2

mycomputeF :: (String -> IO()) -> Int -> IO Int
mycomputeF logF v0 = do
    logF ("add3 " ++ show v0)
    let v1 = add3 v0
    logF ("amul2 " ++ show v1)
    let v2 = mul2 v1
    return v2

main :: IO ()
main = do
    putStrLn "this is log-hs"
    
    res <- mycompute 18
    print res

    resFile <- mycomputeFile 18
    print resFile
    
    resF <- mycomputeF putStrLn 18
    print resF

    message <- openFile "message.txt" WriteMode
    resFileF <- mycomputeF (hPutStrLn message) 18
    hClose message
    print resFileF
