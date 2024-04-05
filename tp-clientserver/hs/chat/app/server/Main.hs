{-# LANGUAGE OverloadedStrings #-}

import qualified Data.Text as T
import qualified Data.Text.IO as T
import qualified Network.WebSockets as WS

import Control.Concurrent
import Control.Exception (finally)

import Net

type Var = MVar (Net WS.Connection)

main :: IO ()
main = do
    var <- newMVar newNet
    _ <- forkIO (handleInput var)
    WS.runServer "0.0.0.0" 9000 (serverApp var)

serverApp :: Var -> WS.PendingConnection -> IO ()
serverApp var pc = do
    conn <- WS.acceptRequest pc
    iConn <- modifyMVar var (return . addConn conn)
    WS.withPingThread conn 30 (return ())
        (finally (handleConn conn) (handleQuit var iConn))

handleConn :: WS.Connection -> IO ()
handleConn conn = do
    _ <- WS.receiveDataMessage conn
    threadDelay 1000000
    handleConn conn

handleQuit :: Var -> Int -> IO ()
handleQuit var iConn = modifyMVar_ var (return . rmConn iConn)

handleInput :: Var -> IO ()
handleInput var = do
    msg <- T.getLine
    modifyMVar_ var  $ \net -> do
        mapInNet (\c -> WS.sendTextData c msg) net
        return net
    handleInput var

